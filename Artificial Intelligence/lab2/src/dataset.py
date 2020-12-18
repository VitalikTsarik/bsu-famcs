from collections import defaultdict

from numpy.linalg import norm
import numpy as np


class DataObject:
    def __init__(self, objectClass, attributes):
        self.objectClass = objectClass
        self.attributes = attributes

    def __str__(self):
        return f'{self.objectClass}: {self.attributes}'

    def __repr__(self):
        return f'{self.objectClass}: {self.attributes}'


class LearningDataSet:
    def __init__(self, values, metric):
        self.values = values
        self.metric = metric
        self.classes = defaultdict(list)
        for value in values:
            self.classes[value.objectClass].append(value.attributes)

    def similarity_with_object(self, x, y):
        if self.metric == 0:
            return norm(x.attributes - y, ord=np.inf)  # maximum norm
        elif self.metric == 1:
            return norm(x.attributes - y)  # euclid
        return norm(x.attributes - y, ord=1)  # L1

    def similarity_with_class(self, x, key):
        classObjects = self.classes[key]
        similarity = np.zeros(len(classObjects))
        for index, value in enumerate(classObjects):
            similarity[index] = self.similarity_with_object(x, value)
        return similarity

    def similarity_with_classes(self, x):
        f = {}
        for key in self.classes:
            s = self.similarity_with_class(x, key)
            f[key] = np.sum(s)
        return f

    def prediction(self, x):
        f = self.similarity_with_classes(x)
        return min(f, key=f.get)
