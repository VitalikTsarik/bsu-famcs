import json
import os
import re
from functools import reduce
from math import gcd
from os.path import dirname

import matplotlib.pyplot as plt

report = open('report.md', 'w')
LETTERS_REGEXPS = {
    'en': re.compile('^[a-zA-Z]+$'),
    'ru': re.compile('^[а-яА-Я]+$')
}
TABLE_COLS = [
    'text length',
    'keyword',
    'length',
    'success'
]

DIFF_THRESHOLD = 0.2

TEXTS_DIR_PATH = os.path.join(dirname(dirname(__file__)), 'plain_text')

with open('frequencies.json', 'r') as data_file:
    frequencies = json.load(data_file)


def read_texts(lengths):
    texts = []
    for filename, length in zip(os.listdir(TEXTS_DIR_PATH), lengths):
        with open(os.path.join(TEXTS_DIR_PATH, 'text0.txt')) as file:
            texts.append(file.read()[:length])
    texts.sort(key=lambda text: len(text))
    return texts


def read_texts_fixed_length(length):
    texts = []
    for filename in os.listdir(TEXTS_DIR_PATH):
        with open(os.path.join(TEXTS_DIR_PATH, filename)) as file:
            texts.append(file.read()[:length])
    texts.sort(key=lambda text: len(text))
    return texts


def add_to_char(char, shift, alphabet):
    if char.lower() not in alphabet:
        return char

    index = ord(char.lower()) - ord(alphabet[0]) + shift
    next_char = alphabet[index % len(alphabet)]
    return next_char.upper() if char.istitle() else next_char


def is_all_letters(string, lang):
    pattern = LETTERS_REGEXPS.get(lang)
    if not pattern:
        raise ValueError('Unsupported language {}'.format(lang))
    return bool(pattern.match(string))


def list_gcd(list):
    return reduce(gcd, list)


def freq_to_sorted_list(dict):
    return sorted([{'letter': k, 'freq': v} for k, v in dict.items()], key=lambda x: x['freq'], reverse=True)


def count_percent(keyword, found_keyword):
    length = len(keyword)
    found_len = len(found_keyword)
    count = 0
    for i in range(min(length, found_len)):
        if keyword[i] == found_keyword[i]:
            count += 1
    return int(100 * count / length)


def print_table_row(*args):
    report.write('|'.join(map(str, args)))
    report.write('\n')


def print_table_head(title):
    report.write('## {}\n'.format(title))
    print_table_row(*TABLE_COLS)
    print_table_row(*['---'] * len(TABLE_COLS))


def print_test(text_len, keyword, found_keyword):
    percent = count_percent(keyword, found_keyword)
    print_table_row(text_len, keyword, len(keyword), f'{percent}%')
    return percent


def add_plot_to_report(x, y, title, xlabel):
    plt.clf()
    plt.plot(x, y)
    plt.ylabel('Percents, %')
    plt.xlabel(f'{xlabel} length, symbols')
    png_path = f'images/{title}.png'
    plt.savefig(png_path)
    report.write('\n![{0}](./{1})\n'.format(title, png_path))
