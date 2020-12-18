import numpy as np

from dataset import DataObject


def read_data(file, lines):
    data = []
    for i in range(lines):
        line = file.readline()
        arr = line.split(sep=',')
        objectClass = arr[-1]
        params = np.array(list(map(int, arr[1:-1])))
        data.append(DataObject(objectClass, params))
    return data
