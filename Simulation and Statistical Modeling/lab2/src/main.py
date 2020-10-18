import numpy as np

from constants import MAX_K, P_GEOMETRIC, P_BERNOULLI, N, LAMBDA_ONE, LAMBDA_TWO
from generators import poisson_generator, poisson_distribution, geometric_distribution, geometric_generator, \
    bernoulli_generator, bernoulli_distribution
from tests import pearson_test


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


def run(title, generator, distribution, args, mean, var, size, isBernoulli=False):
    generated = np.array(list(generator(*args, size)))

    print('\n> {}:'.format(title))
    print_table(generated, mean, var)
    sorted_generated = sorted(generated)

    distr_f = lambda x: distribution(*args, x)
    if isBernoulli:
        p_list = [distr_f(i) for i in (0, 1)]
    else:
        p_list = [distr_f(i) for i in range(MAX_K)]
    p_value, p_delta, k = pearson_test(sorted_generated, p_list)
    print('Pearson:\t' + format_test_result(p_value, p_delta, k))

    print('-' * 50)


if __name__ == '__main__':
    run(
        title=f'Poisson λ = {LAMBDA_ONE}',
        generator=poisson_generator,
        distribution=poisson_distribution,
        args=[LAMBDA_ONE],
        mean=LAMBDA_ONE,
        var=LAMBDA_ONE,
        size=N,
    )

    geometric_mean = 1 / P_GEOMETRIC
    geometric_var = (1 - P_GEOMETRIC) / (P_GEOMETRIC ** 2)
    run(
        title=f'Geomitric p = {P_GEOMETRIC}',
        generator=geometric_generator,
        distribution=geometric_distribution,
        args=[P_GEOMETRIC],
        mean=geometric_mean,
        var=geometric_var,
        size=N,
    )

    bernoulli_var = P_BERNOULLI * (1 - P_BERNOULLI)
    run(
        title=f'Bernoulli p = {P_BERNOULLI}',
        generator=bernoulli_generator,
        distribution=bernoulli_distribution,
        args=[P_BERNOULLI],
        mean=P_BERNOULLI,
        var=bernoulli_var,
        size=N,
        isBernoulli=True,
    )

    run(
        title=f'Poisson λ = {LAMBDA_TWO}',
        generator=poisson_generator,
        distribution=poisson_distribution,
        args=[LAMBDA_TWO],
        mean=LAMBDA_TWO,
        var=LAMBDA_TWO,
        size=N,
    )
