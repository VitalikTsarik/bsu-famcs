from math import exp, factorial, log, ceil
from random import random


def poisson_distribution(lmbda, x):
    return (lmbda ** x) * exp(-lmbda) / factorial(x)


def poisson_generator(lmbda, n):
    for _ in range(n):
        alpha = random()
        n = 0
        while alpha >= exp(-lmbda):
            alpha *= random()
            n += 1
        yield n


def geometric_distribution(p, x):
    q = 1 - p
    return p * (q ** (x - 1))


def geometric_generator(p, n):
    q = 1 - p
    for _ in range(n):
        yield ceil(log(random()) / log(q))


def bernoulli_distribution(p, x):
    q = 1 - p
    return (p ** x) * (q ** (1 - x))


def bernoulli_generator(p, n):
    for _ in range(n):
        yield 0 if random() > p else 1
