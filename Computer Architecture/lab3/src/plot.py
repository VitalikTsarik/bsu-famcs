import numpy as np
from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

data = np.genfromtxt('output.txt', delimiter=' ')

n = int(np.sqrt(len(data)))

data = data.reshape(n, n)

fig = plt.figure()
ax = fig.add_subplot(projection='3d')

x = y = np.linspace(0, 1, n)
x, y = np.meshgrid(x, y)

ax.plot_surface(x, y, data, cmap='viridis')

ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('u')
ax.view_init(35, 250)

plt.show()
