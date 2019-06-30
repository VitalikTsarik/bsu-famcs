import math
from scipy.integrate import fixed_quad

A = 1
B = 2
EPS = 1e-6
QUAD_INTEGRATION_ORDER = 2


def f(x):
    return -1/x + x + x*x


if __name__ == '__main__':
    diff = math.inf
    prev = fixed_quad(f, A, B, n=QUAD_INTEGRATION_ORDER)[0]
    n = 2

    while diff > EPS:
        total = 0
        h = (B-A)/n
        for i in range(n):
            a = A + h*i
            b = a + h
            total += fixed_quad(f, a, b, n=QUAD_INTEGRATION_ORDER)[0]

        n *= 2
        diff = abs(total - prev)
        prev = total

    print('Approximated value: {}\nNumber of intervals: {}'.format(total, n))
