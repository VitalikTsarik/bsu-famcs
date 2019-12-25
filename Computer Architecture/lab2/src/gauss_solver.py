import numpy as np
from mpi4py import MPI


class GaussSolver:
    def __init__(self, data, comm, n):
        self.comm = comm

        self.n = n
        self.indexes = []

        self.A = np.zeros((self.n, self.n))
        self.b = np.zeros(self.n)

        for row in data:
            i = int(row[-1])
            self.indexes.append(i)
            self.A[i] = row[:-2]
            self.b[i] = row[-2]

        self.l = np.zeros(self.n)
        self.r = 0

    def calc(self):
        for i in range(self.n):  # forward elimination
            if i in self.indexes:
                self.b[i] /= self.A[i, i]
                self.A[i] /= self.A[i, i]
                self.__send(i)

            else:
                self._receive(i)

            self.comm.Barrier()

        for i in range(self.n - 1, -1, -1):  # back substitution
            if i in self.indexes:
                self.__send(i)
            else:
                self._receive(i)

            self.comm.Barrier()

        return [[self.b[i], i] for i in self.indexes]

    def __eliminate(self, l, r, cur):
        for i in self.indexes:
            if i != cur:    
                self.b[i] -= r * self.A[i, cur]
                self.A[i] -= l * self.A[i, cur]

    def __send(self, i):
        self.comm.Bcast([self.A[i], MPI.DOUBLE], root=self.comm.rank)
        self.comm.Bcast([self.b[i], MPI.DOUBLE], root=self.comm.rank)

        self.__eliminate(self.A[i], self.b[i], i)

    def _receive(self, i):
        self.comm.Bcast([self.l, MPI.DOUBLE], root=self.comm.rank)
        self.comm.Bcast([self.r, MPI.DOUBLE], root=self.comm.rank)

        self.__eliminate(self.l, self.r, i)
