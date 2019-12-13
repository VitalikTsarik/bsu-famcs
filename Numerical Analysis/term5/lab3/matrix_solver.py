import numpy as np


def solve_tridiag(a, b, c, f):
    n = len(f)
    beta = np.empty(n)
    alpha = np.empty(n - 1)
    x = np.empty(n)

    alpha[0] = b[0] / c[0]
    beta[0] = f[0] / c[0]
    for i in range(1, n - 1):
        din = c[i] - a[i - 1] * alpha[i - 1]
        alpha[i] = b[i] / din
        beta[i] = (f[i] + a[i - 1] * beta[i - 1]) / din
    beta[-1] = (f[-1] + a[-1] * beta[-2]) / (c[-1] - a[-1] * alpha[-1])

    x[-1] = beta[-1]
    for i in reversed(range(n - 1)):
        x[i] = alpha[i] * x[i + 1] + beta[i]

    return x
