from constants import DELTA, MAX_K

PEARSON_THRESHOLD = 0.001


def get_discrete_frequency(sorted_seq, p):
    k = 0
    while k < MAX_K and p[k] > PEARSON_THRESHOLD and k < len(p) - 1:
        k += 1
    v = [0] * (k + 1)
    for el in sorted_seq:
        i = el if el < k else k
        v[i] += 1
    return v, k


def pearson_test(sequence, p_list):
    sequence = sorted(sequence)
    n = len(sequence)
    v, k = get_discrete_frequency(sequence, p_list)
    delta = DELTA[k + 1]
    value = sum([(v[i] - n * p_list[i]) ** 2 / (n * p_list[i]) for i in range(k)])
    return value, delta, k + 1
