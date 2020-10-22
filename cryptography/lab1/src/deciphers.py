import re
from math import ceil

from utils import is_all_letters, list_gcd, freq_to_sorted_list, add_to_char, frequencies, DIFF_THRESHOLD


class Kasiski:
    def __init__(self, length, lang):
        freq = frequencies.get(lang)
        self.lang = lang
        self.known_freq = freq_to_sorted_list(freq)
        self.alphabet = sorted(list(freq.keys()))
        self.length = length

    def get_l_gramms(self, string):
        gramms = {}
        for i in range(len(string) - self.length):
            substr = string[i:i + self.length]
            if not is_all_letters(substr, self.lang):
                continue
            if substr in gramms:
                continue
            matches = [m.start() for m in re.finditer(f'(?={substr})', string)]
            if len(matches) > 1:
                gramms[substr] = matches
        return gramms

    @staticmethod
    def get_differences(array):
        diffs = {}
        for el in array:
            for i in range(len(el) - 1):
                key = el[i + 1] - el[i]
                diffs[key] = diffs.get(key, 0) + 1
        common_diff = diffs[max(diffs, key=lambda k: diffs[k])]
        min_accepted_diff = ceil(common_diff * DIFF_THRESHOLD)
        return [key for key in diffs if diffs[key] > min_accepted_diff]

    def get_length(self, encrypted):
        l_gramms = self.get_l_gramms(encrypted.lower())
        diffs = self.get_differences(list(l_gramms.values()))
        gcd = list_gcd(diffs)
        return gcd


class Analyzer:
    def __init__(self, length, lang):
        freq = frequencies.get(lang)
        self.lang = lang
        self.known_freq = freq_to_sorted_list(freq)
        self.alphabet = sorted(list(freq.keys()))
        self.length = length
        self.length = length

    @staticmethod
    def count_frequencies(string, alphabet):
        letters_count = dict.fromkeys(alphabet, 0)
        escaped = 0
        for c in string:
            if letters_count.get(c.lower()) is not None:
                letters_count[c.lower()] += 1
            else:
                escaped += 1
        string_len = len(string) - escaped
        return {letter: count / string_len for letter, count in letters_count.items()}

    @staticmethod
    def next_freq_closer(value, known_freq):
        return abs(value - known_freq[0]['freq']) > abs(value - known_freq[1]['freq'])

    @staticmethod
    def count_shift(a, b):
        return ord(a['letter']) - ord(b['letter'])

    def find_keyword_letter(self, string):
        shifts = {}
        known_freq = self.known_freq[:]
        freq = freq_to_sorted_list(Analyzer.count_frequencies(string, self.alphabet))
        closest = {}
        for el in freq:
            i = 0
            while i < len(known_freq) - 1:
                closest = known_freq[i]
                if not self.next_freq_closer(el['freq'], known_freq[i:]):
                    break
                i += 1
            shift = self.count_shift(el, closest)
            shifts[shift] = shifts.get(shift, 0) + 1
        common_shift = max(shifts, key=lambda k: shifts[k])
        return add_to_char(self.alphabet[0], common_shift, self.alphabet)

    def find_keyword(self, string):
        parts = [string[i::self.length] for i in range(self.length)]
        letters = list(map(self.find_keyword_letter, parts))
        return ''.join(letters)
