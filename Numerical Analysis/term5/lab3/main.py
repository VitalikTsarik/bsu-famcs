import numpy as np

from matrix_solver import solve_tridiag
from utils import plot, error

h = 0.1
tau = 0.1
(x0, x1) = (0, 1)
(t0, t1) = (0, 1)


def fi(x, t):
    return (x ** 2 + 2 * t + 3) / ((t + 1) ** 2)


def exact_solution(x, t):
    return (x ** 2 + 1) / (t + 1)


def init_data(h, tau):
    x = np.arange(x0, x1 + h, h)
    t = np.arange(t0, t1 + tau, tau)
    n1 = len(x)
    n2 = len(t)

    y = np.empty((n1, n2))

    for i in range(n1):
        y[i, 0] = x[i] ** 2 + 1

    return x, t, n1, n2, y


def solve_explicit(h, tau):
    x, t, n1, n2, y = init_data(h, tau)

    for j in range(n2):
        y[0, j] = 1 / (t[j] + 1)
        y[-1, j] = 2 / (t[j] + 1)

    for j in range(n2 - 1):
        for i in range(1, n1 - 1):
            y[i, j + 1] = tau * ((y[i + 1, j] + y[i - 1, j] - 2 * y[i, j]) / (h ** 2) - fi(x[i], t[j])) + y[i, j]

    return x, t, y


def solve_implicit(h, tau, iteration):
    x, t, n1, n2, y = init_data(h, tau)

    for j in range(n2 - 1):
        y[:, j + 1] = iteration(h, tau, y, x, t, j, n1)

    return x, t, y


def pure_implicit_iteration(h, tau, y, x, t, j, n):
    a = np.empty(n - 1)
    av = np.vectorize(lambda x: -1 / h ** 2)
    a[:-1] = av(x[1:-1])
    a[-1] = 0

    b = np.empty(n - 1)
    b[0] = 0
    bv = np.vectorize(lambda x: -1 / h ** 2)
    b[1:] = bv(x[1:-1])

    c = np.empty(n)
    c[0] = 1
    cv = np.vectorize(lambda x: -(2 / h ** 2 + 1 / tau))
    c[1:-1] = cv(x[1:-1])
    c[-1] = 1

    f = np.empty(n)
    f[0] = 1 / (t[j] + 1)
    fv = np.vectorize(lambda x, y: fi(x, t[j]) - y / tau)
    f[1:-1] = fv(x[1:-1], y[1:-1, j])
    f[-1] = 2 / (t[j] + 1)

    return solve_tridiag(a, b, c, f)


def crank_nicolson_iteration(h, tau, y, x, t, j, n):
    a = np.empty(n - 1)
    av = np.vectorize(lambda x: -1 / (2 * h ** 2))
    a[:-1] = av(x[1:-1])
    a[-1] = 0

    b = np.empty(n - 1)
    b[0] = 0
    bv = np.vectorize(lambda x: -1 / (2 * h ** 2))
    b[1:] = bv(x[1:-1])

    c = np.empty(n)
    c[0] = 1
    cv = np.vectorize(lambda x: -(1 / h ** 2 + 1 / tau))
    c[1:-1] = cv(x[1:-1])
    c[-1] = 1

    f = np.empty(n)
    f[0] = 1 / (t[j + 1] + 1)
    fv = np.vectorize(lambda x, i:
                      fi(x, t[j] + tau / 2) - y[i, j] / tau - (y[i + 1, j] + y[i - 1, j] - 2 * y[i, j]) / (2 * h ** 2))
    f[1:-1] = fv(x[1:-1], range(1, n - 1))
    f[-1] = 2 / (t[j + 1] + 1)

    return solve_tridiag(a, b, c, f)


if __name__ == '__main__':
    x, t, y = solve_explicit(h, tau)
    plot(x, t, y)
    print(error(y, x, t, exact_solution))

    x, t, y = solve_explicit(h, h ** 2 / 2)
    plot(x, t, y)
    print(error(y, x, t, exact_solution))

    x, t, y = solve_implicit(h, tau, pure_implicit_iteration)
    print(error(y, x, t, exact_solution))

    x, t, y = solve_implicit(h, tau, crank_nicolson_iteration)
    print(error(y, x, t, exact_solution))
