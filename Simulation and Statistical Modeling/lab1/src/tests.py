from bisect import bisect_right
from math import sqrt

import numpy as np

from constants import DELTA, MAX_K

PEARSON_THRESHOLD = 0.01
KOLMOGOROV_DELTA = 1.36


def get_frequency(sorted_seq, k):
    min_el = sorted_seq[0]
    max_el = sorted_seq[-1]
    step = (max_el - min_el) / (k + 1)
    segments = np.arange(min_el, max_el, step)
    v = [0] * k
    last_position = 0
    for i in range(k):
        position = bisect_right(sorted_seq, segments[i + 1])
        v[i] = position - last_position
        last_position = position
    return v, segments


def pearson_test(sequence, p_list):
    sequence = sorted(sequence)
    n = len(sequence)
    v, segments = get_frequency(sequence, MAX_K)
    delta = DELTA[MAX_K]
    value = sum([(v[i] - n * p_list[i]) ** 2 / (n * p_list[i]) for i in range(MAX_K)])
    return value, delta, MAX_K


def kolmogorov_smirnov_test(sequence):
    sequence = sorted(sequence)
    n = len(sequence)
    test_seq = np.array([float(i + 1) / n for i in range(n)])
    max_diff = max(list(map(abs, test_seq - sequence)))
    value = sqrt(n) * max_diff
    return value, KOLMOGOROV_DELTA
