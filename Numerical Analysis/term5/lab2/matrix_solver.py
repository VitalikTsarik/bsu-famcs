import numpy as np


def solve_tridiag(a, b, c, f):
    n = len(f)
    beta = np.zeros(n)
    alpha = np.zeros(n)
    x = np.zeros(n)

    alpha[0] = 0
    beta[0] = 0
    for i in range(n - 1):
        din = c[i] - a[i] * alpha[i]
        alpha[i + 1] = b[i] / din
        beta[i + 1] = (f[i] + a[i] * beta[i]) / din

    x[n - 1] = beta[n - 1]
    for i in reversed(range(n - 1)):
        x[i] = alpha[i + 1] * x[i + 1] + beta[i]

    return np.array(x)
