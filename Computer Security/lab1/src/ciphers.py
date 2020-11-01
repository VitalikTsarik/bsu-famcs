from utils import add_to_char, frequencies, freq_to_sorted_list


class Vigenere:
    def __init__(self, keyword, lang):
        self.lang = lang
        freq = frequencies.get(lang)
        self.known_freq = freq_to_sorted_list(freq)
        self.alphabet = sorted(list(freq.keys()))
        self.keyword = keyword
        self.shifts = [ord(c.lower()) - ord(self.alphabet[0]) for c in keyword]

    def process_string(self, string, sign=1):
        shifts = self.shifts
        period = len(self.keyword)
        parts = [string[i::period] for i in range(period)]

        result_parts = [self.caesar_string(parts[i], sign * shifts[i], self.alphabet) for i in range(period)]

        letters = []
        for j in range(len(result_parts[0])):
            for i in range(period):
                if j < len(result_parts[i]):
                    letters.append(result_parts[i][j])

        return ''.join(letters)

    @staticmethod
    def caesar_string(string, shift, alphabet):
        return ''.join([add_to_char(c, shift, alphabet) for c in string])

    def encrypt(self, string):
        return self.process_string(string)

    def decrypt(self, string):
        return self.process_string(string, -1)
