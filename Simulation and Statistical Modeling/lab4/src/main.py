from math import e, sqrt

import matplotlib.pyplot as plt
from numpy import var
from scipy.stats import uniform, laplace

theoretical_value = [
    2.000048683645068,
    3.835724597380394,
]


# (-∞,+∞)
def integrand1(x):
    return e ** (-x ** 4) * sqrt(1 + x ** 4)


# [-2, 2] = [loc, loc + scale]
kwargs = {'loc': -2, 'scale': 4}


def integrand2(args):
    x, y = args
    if 1 <= x ** 2 + y ** 2 <= 4:
        return 1 / (x ** 2 + y ** 4)
    else:
        return 0


def generate_two_dimension_uniform(size):
    return list(zip(uniform.rvs(**kwargs, size=size), uniform.rvs(**kwargs, size=size)))


def two_dimension_uniform_pdf(args):
    x, y = args
    return uniform.pdf(x, **kwargs) * uniform.pdf(y, **kwargs)


def monte_carlo_method(integrand, values, pdf):
    value = sum([integrand(val) / pdf(val) for val in values]) / len(values)
    error = error_probability(values)
    return value, error


def error_probability(values):
    return 0.6745 * sqrt(var(values) / len(values))


def draw(real, errors, theory):
    plt.figure(figsize=(20, 8))
    x = iterations
    plt.plot(x, [theory] * len(x), label='theory')
    plt.plot(x, real, label='real')
    plt.xscale('log', base=5)
    plt.tick_params(labelsize=26)
    plt.xticks(x, x)
    plt.xlabel('iterations', fontsize=30)
    plt.ylabel('value', fontsize=30)
    plt.legend()
    plt.show()

    plt.figure(figsize=(20, 8))
    x = iterations
    y = errors
    plt.plot(x, y)
    plt.xscale('log', base=5)
    plt.tick_params(labelsize=26)
    plt.xticks(x, x)
    plt.xlabel('iterations', fontsize=30)
    plt.ylabel('error probability', fontsize=30)
    plt.show()


def run(integrand, rvs, pdf, iterations, theoreticalValue):
    values = []
    errors = []
    for size in iterations:
        value, error = monte_carlo_method(integrand, rvs(size=size), pdf)
        values.append(value)
        errors.append(error)
    draw(values, errors, theoreticalValue)


if __name__ == '__main__':
    iterations = [5 ** i for i in range(1, 8)]
    run(integrand1, laplace.rvs, laplace.pdf, iterations, theoretical_value[0])
    run(integrand2, generate_two_dimension_uniform, two_dimension_uniform_pdf, iterations, theoretical_value[1])
