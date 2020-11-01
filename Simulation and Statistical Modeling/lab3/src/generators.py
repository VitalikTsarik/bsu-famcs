from math import exp, log, erf, sqrt
from random import random


def get_next_standard_gauss():
    return sum([random() for _ in range(12)]) - 6


def get_next_gauss(m, s):
    return m + s * get_next_standard_gauss()


def gauss_generator(m, s, n):
    for _ in range(n):
        z = get_next_standard_gauss()
        yield m + s * z


def gauss_distribution(m, s, x):
    return 0.5 * (1 + erf((x - m) / (sqrt(2) * s)))


def exponential_generator(lmbda, n):
    for _ in range(n):
        yield (-1) / lmbda * log(random())


def exponential_distribution(lmbda, x):
    return 1 - exp(-lmbda * x)


def weibull_generator(lmbda, c, n):
    for _ in range(n):
        yield ((-1) / lmbda * log(random())) ** (1 / c)


def weibull_distribution(lmbda, c, x):
    return 1 - exp(-((x / lmbda) ** c))


def logistic_generator(mu, k, n):
    for _ in range(n):
        y = random()
        yield mu + k * log(y / (1 - y))


def logistic_distribution(mu, k, x):
    return 1 / (1 + exp(-((x - mu) / k)))


def laplace_generator(lmbda, n):
    for _ in range(n):
        y = random()
        if y < 0.5:
            yield 1 / lmbda * log(2 * y)
        else:
            yield -1 / lmbda * log(2 * (1 - y))


def laplace_distribution(lmbda, x):
    if x < 0:
        return 1 / 2 * exp(lmbda * x)
    else:
        return 1 - 1 / 2 * exp(-lmbda * x)
