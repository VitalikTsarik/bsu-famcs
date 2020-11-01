import os

from ciphers import Vigenere
from deciphers import Kasiski, Analyzer
from utils import print_test, print_table_head, add_plot_to_report, read_texts

with open('texts/big.txt') as data_file:
    data = data_file.read()

LANG = 'en'
KEY_WORDS = (
    'WE',
    'DOG',
    'FOUR',
    'BLUER',
    'ORANGE',
    'ZIPLOCK',
    'SOFTWARE',
    'WONDERFUL',
    'KICKBOXING',
    'OPPOSITIONS',
)
TEXT_LENGTHS = (
    500,
    1000,
    3000,
    4000,
    5000,
    5500,
    6000,
    6500,
    7000,
    9000,
)

kasiski = Kasiski(3, LANG)


def run_test(text, keyword):
    encrypted = Vigenere(keyword, LANG).encrypt(text)
    analyzer = Analyzer(kasiski.get_length(encrypted), LANG)
    found_keyword = analyzer.find_keyword(encrypted).upper()
    return print_test(len(text), keyword, found_keyword)


if __name__ == '__main__':
    texts = read_texts(TEXT_LENGTHS)

    print_table_head('Fixed keyword length')
    percents = []

    for text in texts:
        percents.append(run_test(text, KEY_WORDS[4]))
    add_plot_to_report(TEXT_LENGTHS, percents, 'test1', 'Text')

    print_table_head('Fixed text length')
    percents = []
    for keyword in KEY_WORDS:
        percents.append(run_test(texts[6], keyword))
    add_plot_to_report(list(map(len, KEY_WORDS)), percents, 'test2', 'Keyword')

    print(f'report generated in {os.getcwd()}/report.md')
