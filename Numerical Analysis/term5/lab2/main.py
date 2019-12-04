from math import cos

import numpy as np
import matplotlib.pyplot as plt

from matrix_solver import solve_tridiag

h = 0.05
[A, B] = [-1, 1]


def init_data(h):
    x = np.arange(A, B + h, h)
    n = len(x)

    a = np.empty(n - 1)
    av = np.vectorize(lambda x: -(1 / (h * h) + (1 + x) / (4 * h)))
    a[:-1] = av(x[1:-1])
    a[-1] = 1 / h

    b = np.empty(n - 1)
    b[0] = -1 / h
    bv = np.vectorize(lambda x: -(1 / (h * h) - (1 + x) / (4 * h)))
    b[1:] = bv(x[1:-1])

    c = np.empty(n)
    c[0] = -(1 / h + h / 2 * cos(1 / 2))
    cv = np.vectorize(lambda x: -(2 / (h * h) + cos(x / 2)))
    c[1:-1] = cv(x[1:-1])
    c[-1] = 1 / h + h / 2 * cos(1 / 2)

    f = np.empty(n)
    f[0] = -h / 4
    fv = np.vectorize(lambda x: -(x / 2 + 1))
    f[1:-1] = fv(x[1:-1])
    f[-1] = 1 + h / 4

    return a, b, c, f, x


def runge_rule(y1, y2, order=2):
    return np.amax((abs(y1 - y2))) / (2 ** order - 1)


def solve(h):
    a, b, c, f, x = init_data(h)
    y = solve_tridiag(a, b, c, f)
    return x, y


if __name__ == '__main__':
    x1, y1 = solve(h)
    x2, y2 = solve(h * 2)
    print(runge_rule(y1[::2], y2))

    plt.plot(x1, y1)
    plt.show()
