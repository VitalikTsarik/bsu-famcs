import sys

import numpy as np
from numpy import linalg as la
from mpi4py import MPI

from gauss_solver import GaussSolver
from utils import formatting, str_to_row, format_action, Timer, write_vector, read_input

MASTER = 0
inp = open('input.txt', 'r')
out = open('output.txt', 'w')

if __name__ == '__main__':
    comm = MPI.COMM_WORLD
    rows = []

    if comm.rank == MASTER:
        n, A, b = read_input(inp)

        totalTimer = Timer('master')

        comm.bcast(n, root=MASTER)

        step = n // comm.size
        master_count = step + n % comm.size

        rows = [A[i] + [b[i], i] for i in range(master_count)]

        cur = master_count
        for proc in range(1, comm.size):
            for i in range(step):
                comm.send(A[cur + i] + [b[cur + i], cur + i], dest=proc)  # send row with index as last element
            cur += step

        print(formatting(comm.rank, format_action('receive', rows=rows)))

        g = GaussSolver(np.array(rows), comm, n)
        res = g.calc()

        print(formatting(comm.rank, format_action('result', rows=res)))

        for proc in range(1, comm.size):
            res += comm.recv(source=proc)

        res.sort(key=lambda row: row[-1])

        x = []
        for row in res:
            x.append(row[0])

        totalTimer.finish()
        
        print(formatting(comm.rank, format_action('result')))

        write_vector(x, out)

        print(formatting(comm.rank, format_action('answer', x=x)))

    else:
        procTimer = Timer('proc{}'.format(comm.rank))
        n = comm.bcast(None, root=MASTER)
        step = n // comm.size

        if not step:
            sys.exit()

        for i in range(step):
            rows.append(comm.recv(source=MASTER))

        print(formatting(comm.rank, format_action('receive', rows=rows)))

        g = GaussSolver(np.array(rows), comm, n)

        inversed = g.calc()

        print(formatting(comm.rank, format_action('result', rows=inversed)))

        comm.send(inversed, dest=MASTER)
        procTimer.finish()
