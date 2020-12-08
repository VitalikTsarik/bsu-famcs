from tabulate import tabulate
import matplotlib.pyplot as plt
import numpy as np

headers = ['Processes', 'total time, s', 'back substitution time, s']

with open('../reports/output.txt', 'r') as file:
    size = int(file.readline())

    table = [file.readline().split() for _ in range(size)]
    print(tabulate(table, headers, tablefmt='github'))

    data = np.array(table)
    block_sizes = list(map(int, data[:, 0]))
    plt.xlabel('Processes')
    plt.ylabel('Total time, s')
    plt.plot(block_sizes, list(map(float, data[:, 1])))
    # plt.plot(block_sizes, list(map(float, data[:, 2])))
    plt.show()
