from math import gamma, pi

import numpy as np

from constants import MAX_K, N
from generators import weibull_generator, weibull_distribution, exponential_generator, exponential_distribution, \
    gauss_generator, gauss_distribution, logistic_generator, logistic_distribution, laplace_distribution, \
    laplace_generator
from tests import pearson_test, kolmogorov_smirnov_test


def print_table(generated, theory_mean, theory_var):
    template = '\t\t\tGenerated\tTheory\t| Diff\nMean\t\t{0:.4f}\t\t{2:.4f}\t| {4:.2E}\nVariance\t{1:.4f}\t\t{3:.4f}\t| {5:.2E}'

    mean_diff = abs(generated.mean() - theory_mean)
    var_diff = abs(generated.var() - theory_var)
    print(template.format(generated.mean(), generated.var(), theory_mean, theory_var, mean_diff, var_diff))


def format_test_result(value, delta, k=None):
    result = f'{value:.10f} < {delta:.4f}'
    if k:
        return f'k = {k}, ' + result
    return result


def run(title, generator, distribution, args, mean, var, size):
    generated = np.array(list(generator(*args, size)))

    print(f'\n> {title}:')
    print_table(generated, mean, var)
    sorted_generated = sorted(generated)

    distr_f = lambda x: distribution(*args, x)
    p_list = [distr_f(i) for i in range(1, MAX_K)]
    p_value, p_delta, k = pearson_test(sorted_generated, p_list)
    print('Pearson:\t' + format_test_result(p_value, p_delta, k))

    p_value, p_delta = kolmogorov_smirnov_test(sorted_generated)
    print('Kolmogorov:\t' + format_test_result(p_value, p_delta))

    print('-' * 50)


if __name__ == '__main__':
    m = 4
    s = 25
    run(
        title=f'Gauss m = {m}, σ^2 = {s}',
        generator=gauss_generator,
        distribution=gauss_distribution,
        args=[m, s],
        mean=m,
        var=s ** 2,
        size=N,
    )

    a = 0.5
    mean = a ** (-1)
    var = a ** (-2)
    run(
        title=f'Exponential a = {a}',
        generator=exponential_generator,
        distribution=exponential_distribution,
        args=[a],
        mean=mean,
        var=var,
        size=N,
    )

    a = 4
    b = 0.5
    mean = (a ** (-1 / b)) * gamma(1 + 1 / b)
    var = (a ** (-2 / b)) * (gamma(1 + 2 / b) - (gamma(1 + 1 / b)) ** 2)
    run(
        title=f'Weibull a = {a}, b = {b}',
        generator=weibull_generator,
        distribution=weibull_distribution,
        args=[a, b],
        mean=mean,
        var=var,
        size=N,
    )

    m = 0
    s = 1
    run(
        title=f'Gauss m = {m}, σ^2 = {s}',
        generator=gauss_generator,
        distribution=gauss_distribution,
        args=[m, s],
        mean=m,
        var=s ** 2,
        size=N,
    )

    a = 2
    b = 3
    mean = a
    var = (pi ** 2) / 3 * b ** 2
    run(
        title=f'Logistic a = {a}, b = {b}',
        generator=logistic_generator,
        distribution=logistic_distribution,
        args=[a, b],
        mean=mean,
        var=var,
        size=N,
    )

    a = 2
    mean = 0
    var = 2 / (a ** 2)
    run(
        title=f'Laplace a = {a}',
        generator=laplace_generator,
        distribution=laplace_distribution,
        args=[a],
        mean=mean,
        var=var,
        size=N,
    )
