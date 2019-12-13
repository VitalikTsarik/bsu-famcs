import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


def error(y, x, t, solution):
    x, t = np.meshgrid(x, t, indexing='ij')
    u = solution(x, t)

    return np.max(np.abs(y - u))


def plot(x, t, y):
    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')

    x, t = np.meshgrid(x, t, indexing='ij')

    ax.plot_surface(x, t, y, cmap='viridis')

    ax.set_xlabel('x')
    ax.set_ylabel('t')
    ax.set_zlabel('u')
    ax.view_init(35, 65)

    plt.show()
