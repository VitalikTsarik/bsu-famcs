import math
import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import lagrange

n = (10, 20, 40)
A = 1
B = 2
RANK = 3
NUMBER_OF_NODES = RANK + 1


def f(x):
    return -1/x + x + x*x


def chebyshev_nodes(a, b, n):
    return np.array(
        [(a + b) / 2.0 + (b - a) / 2.0 * math.cos((2 * i + 1) / (2.0 * n + 2.0) * math.pi)
         for i in range(n)], dtype='float')


if __name__ == '__main__':
    x = np.linspace(A, B, 10000)
    plt.plot(x, f(x))
    plt.title('f(x)')
    plt.show()

    for n_i in n:
        beg = A
        step = (B - A) / n_i
        end = beg

        x = []
        y = []
        for i in range(n_i):
            beg = end
            end += step

            nodes = chebyshev_nodes(beg, end, NUMBER_OF_NODES)
            polynom = lagrange(nodes, f(nodes))

            x_i = np.linspace(beg, end, 100)
            x.extend(x_i)
            y.extend(polynom(x_i))

        plt.title('polynomial approximation, n = {}'.format(n_i))
        plt.plot(x, y, 'o', ls='-', ms=4, markevery=100, label='polynom')
        plt.show()
