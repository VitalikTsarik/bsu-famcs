from math import sin

import numpy as np
from mpi4py import MPI

from utils import Timer

MASTER = 0
LAST = -1

a = 0
b = 1

n = 128

h = (b - a) / (n + 1)

N = n + 2
EPS = 1e-3


def f(x, y):
    return x * y


def g1(y):
    return y ** 2


def g2(y):
    return sin(y)


def g3(x):
    return x ** 3


def g4(x):
    return x ** 2


if __name__ == '__main__':
    totalTimer = None
    comm = MPI.COMM_WORLD
    LAST = comm.size - 1

    proc_n = n // comm.size + 2

    u = np.zeros((proc_n, N))

    for i in range(proc_n):
        u[i, 0] = g1(((n // comm.size + 1) * comm.rank + i) * h)
        u[i, -1] = g2(((n // comm.size + 1) * comm.rank + i) * h)

    if comm.rank == LAST:
        for i in range(N):
            u[-1, i] = g4(h * i)

    if comm.rank == MASTER:
        totalTimer = Timer('master')
        for i in range(N):
            u[0, i] = g3(h * i)

    iter = 0
    diff_max_global = EPS + 1

    while diff_max_global > EPS:
        if comm.rank != LAST:
            comm.send(u[n // comm.size], dest=(comm.rank + 1))
            u[n // comm.size + 1] = comm.recv(source=(comm.rank + 1))

        if comm.rank != MASTER:
            u[0] = comm.recv(source=(comm.rank - 1))
            comm.send(u[1], dest=(comm.rank - 1))

        diff_proc_max = 0

        for i in range(1, n // comm.size + 1):
            for j in range(1, n + 1):
                temp = u[i, j]
                u[i, j] = 0.25 * (u[i, j - 1] + u[i, j + 1] + u[i - 1, j] + u[i + 1, j] - h * h * f(h * i, h * j))

                dm = abs(temp - u[i, j])
                if diff_proc_max < dm:
                    diff_proc_max = dm

        diff_max_global = comm.reduce(diff_proc_max, op=MPI.MAX, root=MASTER)
        diff_max_global = comm.bcast(diff_max_global, root=MASTER)

        iter += 1

    if comm.rank == MASTER:
        print(f'[END] iterations: {iter}')
        with open('output.txt', 'w') as file:
            for i in range(n // comm.size + 1):
                for j in range(N):
                    file.write(f'{u[i, j]} ')

            vec = np.zeros(N)

            for k in range(1, comm.size):
                size = (n // comm.size + 2) if k == LAST else (n // comm.size + 1)
                for i in range(1, size):
                    vec = comm.recv(source=k)
                    for val in vec:
                        file.write(f'{val} ')

        totalTimer.finish()

    else:
        for i in range((n // comm.size + 2) if comm.rank == LAST else (n // comm.size + 1)):
            comm.send(u[i], dest=MASTER)
