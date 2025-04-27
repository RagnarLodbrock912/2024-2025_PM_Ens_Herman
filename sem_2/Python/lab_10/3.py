import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

t = np.linspace(0, 2 * np.pi, 1000)

fig, ax = plt.subplots()
line, = ax.plot([], [], lw=2)

ax.set_xlim(-1.2, 1.2)
ax.set_ylim(-1.2, 1.2)
ax.set_aspect('equal')
ax.grid(True)
ax.set_title("Анимация фигуры Лисажу")

def update(frame):
    ratio = frame / 100
    a = 1
    b = 1 / ratio if ratio != 0 else 1e6
    x = np.sin(a * t)
    y = np.sin(b * t)
    line.set_data(x, y)
    return line,

ani = FuncAnimation(fig, update, frames=101, interval=50, blit=True)

plt.show()
