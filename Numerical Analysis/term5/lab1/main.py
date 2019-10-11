import numpy as np
from tabulate import tabulate

A, B = 1, 2
TAU = 0.05
U10 = 1
U20 = -1
ORDER = 2


def f1(t, u1, u2):
    return u2


def f2(t, u1, u2):
    return -((3 * t + 2) * u2 + u1) / (t * (t + 1))


def u(t):
    return 1 / t


def du(t):
    return -1 / (t * t)


def explicit_trapezoid(f1, f2, t, dt, y1_0, y2_0):
    y1 = np.empty(len(t))
    y2 = np.empty(len(t))
    y1[0] = y1_0
    y2[0] = y2_0

    for i in range(len(t) - 1):
        _y1 = y1[i] + dt * f1(t[i], y1[i], y2[i])
        _y2 = y2[i] + dt * f2(t[i], y1[i], y2[i])

        y1[i + 1] = y1[i] + dt / 2 * (f1(t[i], y1[i], y2[i]) + f1(t[i + 1], _y1, _y2))
        y2[i + 1] = y2[i] + dt / 2 * (f2(t[i], y1[i], y2[i]) + f2(t[i + 1], _y1, _y2))

    return y1, y2


def adams(f1, f2, t, dt, y1_0, y2_0):
    y1 = np.empty(len(t))
    y2 = np.empty(len(t))
    y1[0] = y1_0
    y2[0] = y2_0

    y1[0:2], y2[0:2] = explicit_trapezoid(f1, f2, t[0:2], dt, y1_0, y2_0)

    for i in range(1, len(t) - 1):
        y1[i + 1] = y1[i] + dt / 2 * (3 * f1(t[i], y1[i], y2[i]) - f1(t[i - 1], y1[i - 1], y2[i - 1]))
        y2[i + 1] = y2[i] + dt / 2 * (3 * f2(t[i], y1[i], y2[i]) - f2(t[i - 1], y1[i - 1], y2[i - 1]))

    return y1, y2


def implicit_trapezoid(t, dt, y1_0, y2_0):
    y1 = np.empty(len(t))
    y2 = np.empty(len(t))
    y1[0] = y1_0
    y2[0] = y2_0

    for i in range(len(t) - 1):
        a = np.empty((2, 2))
        a[0][0] = 1
        a[0][1] = -dt / 2
        a[1][0] = dt / 2 / (t[i + 1] * (t[i + 1] + 1))
        a[1][1] = 1 + dt / 2 * (3 * t[i + 1] + 2) / (t[i + 1] * (t[i + 1] + 1))

        b = np.empty(2)
        b[0] = y1[i] + dt / 2 * y2[i]
        b[1] = y2[i] - dt / 2 * ((3 * t[i] + 2) * y2[i] + y1[i]) / (t[i] * (t[i] + 1))

        y1[i + 1], y2[i + 1] = np.linalg.solve(a, b)

    return y1, y2


def max_norm(y1, y2, u1, u2):
    return np.amax((abs(y1 - u1), abs(y2 - u2)))


def runge_rule(y1, y2, _y1, _y2, order=2):
    return np.amax((abs(y1 - _y1[::2]), abs(y2 - _y2[::2]))) / (2 ** order - 1)


if __name__ == '__main__':
    t = np.arange(A, B + TAU, TAU)
    y1_exp_trap, y2_exp_trap = explicit_trapezoid(f1, f2, t, TAU, U10, U20)
    y1_adams, y2_adams = adams(f1, f2, t, TAU, U10, U20)
    y1_imp_trap, y2_imp_trap = implicit_trapezoid(t, TAU, U10, U20)
    u1 = u(t)
    u2 = du(t)

    tabular_data = {
        'j': range(len(t)),
        't_j': t,
        'u': u1,
        'u\'': u2,
        'y1 expl trap': y1_exp_trap,
        'y2 expl trap': y2_exp_trap,
        'y1 adams': y1_adams,
        'y2 adams': y2_adams,
        'y1 imp trap': y1_imp_trap,
        'y2 imp trap': y2_imp_trap,
    }

    headers_latex = ('j', 't_j', 'u(t_j)', 'u\'(t_j)', 'y_1(t_j)', 'y_2(t_j)',
                     'y_1(t_j)', 'y_2(t_j)', 'y_1(t_j)', 'y_2(t_j)')
    floatfmt = ('.1f', '.2f', '.4f', '.4f', '.4f', '.4f', '.4f', '.4f', '.4f', '.4f')

    print(tabulate(tabular_data, headers=headers_latex, tablefmt='latex_booktabs', floatfmt=floatfmt))

    print(max_norm(y1_exp_trap, y2_exp_trap, u1, u2))
    print(max_norm(y1_adams, y2_adams, u1, u2))
    print(max_norm(y1_imp_trap, y2_imp_trap, u1, u2))

    t = np.arange(A, B + TAU / 2, TAU / 2)
    _y1_exp_trap, _y2_exp_trap = explicit_trapezoid(f1, f2, t, TAU / 2, U10, U20)
    _y1_adams, _y2_adams = adams(f1, f2, t, TAU / 2, U10, U20)
    _y1_imp_trap, _y2_imp_trap = implicit_trapezoid(t, TAU / 2, U10, U20)

    print(runge_rule(y1_exp_trap, y2_exp_trap, _y1_exp_trap, _y2_exp_trap))
    print(runge_rule(y1_imp_trap, y2_imp_trap, _y1_imp_trap, _y2_imp_trap))
