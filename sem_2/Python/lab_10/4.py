import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider

fig, (ax1, ax2, ax3) = plt.subplots(3, 1, figsize=(8, 8))

x = np.linspace(0, 10, 1000)

A1_init, f1_init = 1, 1
A2_init, f2_init = 1, 1

def wave1(x, A1, f1):
    return A1 * np.sin(f1 * x)

def wave2(x, A2, f2):
    return A2 * np.sin(f2 * x)

y1 = wave1(x, A1_init, f1_init)
y2 = wave2(x, A2_init, f2_init)
y_sum = y1 + y2

line1, = ax1.plot(x, y1, label='Wave 1', color='b')
ax1.set_title('Wave 1')
ax1.set_ylim(-2, 2)
ax1.set_xlabel('x')
ax1.set_ylabel('Amplitude')
ax1.grid(True)

line2, = ax2.plot(x, y2, label='Wave 2', color='r')
ax2.set_title('Wave 2')
ax2.set_ylim(-2, 2)
ax2.set_xlabel('x')
ax2.set_ylabel('Amplitude')
ax2.grid(True)

line_sum, = ax3.plot(x, y_sum, label='Sum of Waves', color='g')
ax3.set_title('Sum of Waves')
ax3.set_ylim(-4, 4)
ax3.set_xlabel('x')
ax3.set_ylabel('Amplitude')
ax3.grid(True)

axcolor = 'lightgoldenrodyellow'
ax_A1 = plt.axes([0.1, 0.01, 0.65, 0.03], facecolor=axcolor)
ax_f1 = plt.axes([0.1, 0.06, 0.65, 0.03], facecolor=axcolor)
ax_A2 = plt.axes([0.1, 0.11, 0.65, 0.03], facecolor=axcolor)
ax_f2 = plt.axes([0.1, 0.16, 0.65, 0.03], facecolor=axcolor)

s_A1 = Slider(ax_A1, 'A1', 0.1, 2.0, valinit=A1_init)
s_f1 = Slider(ax_f1, 'f1', 0.1, 10.0, valinit=f1_init)
s_A2 = Slider(ax_A2, 'A2', 0.1, 2.0, valinit=A2_init)
s_f2 = Slider(ax_f2, 'f2', 0.1, 10.0, valinit=f2_init)

def update(val):
    A1 = s_A1.val
    f1 = s_f1.val
    A2 = s_A2.val
    f2 = s_f2.val

    y1 = wave1(x, A1, f1)
    y2 = wave2(x, A2, f2)
    y_sum = y1 + y2

    line1.set_ydata(y1)
    line2.set_ydata(y2)
    line_sum.set_ydata(y_sum)

    fig.canvas.draw_idle()

s_A1.on_changed(update)
s_f1.on_changed(update)
s_A2.on_changed(update)
s_f2.on_changed(update)

plt.subplots_adjust(left=0.1, bottom=0.25)
plt.show()
