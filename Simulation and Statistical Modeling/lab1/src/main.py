from random import random

from constants import MAX_K
from generators import multiplicative_congruential_generator, maclaren_marsaglia_generator
from tests import pearson_test, kolmogorov_smirnov_test

N = 1000
K = 64
M = 2 ** 31
ALPHA_0 = 16807
BETA = ALPHA_0


def format_test_result(value, delta, k=None):
    result = f'{value:.3f} < {delta:.3f}'
    if k:
        return f'k = {k}, ' + result
    return result


if __name__ == '__main__':
    mcg = list(multiplicative_congruential_generator(ALPHA_0, BETA, M, N + K))
    mcg_result = mcg[:N]
    print(f'Multiplicative Congruential Generator: {mcg[:N]}')

    random_sequence = [random() for _ in range(N)]
    mmg_result = list(maclaren_marsaglia_generator(mcg, random_sequence, K, N))
    print(f'MacLaren-Marsaglia Generator: {mmg_result}')

    p = [1.0 / MAX_K] * MAX_K
    mcg_person_result = pearson_test(mcg_result, p_list=p)
    mmg_person_result = pearson_test(mmg_result, p_list=p)
    mcg_kolmogorov_result = kolmogorov_smirnov_test(mcg_result)
    mmg_kolmogorov_result = kolmogorov_smirnov_test(mmg_result)

    print('\nMultiplicative Congruential Generator:')
    print('\tKolmogorov test ' + format_test_result(*mcg_kolmogorov_result))
    print('\tPearson test: ' + format_test_result(*mcg_person_result))

    print('\nMacLaren-Marsaglia Generator:')
    print('\tKolmogorov test ' + format_test_result(*mmg_kolmogorov_result))
    print('\tPearson test: ' + format_test_result(*mmg_person_result))
