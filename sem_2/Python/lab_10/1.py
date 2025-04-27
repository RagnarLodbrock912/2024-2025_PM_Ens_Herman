import numpy as np
import matplotlib.pyplot as plt
from scipy.special import legendre

x = np.linspace(-1, 1, 1000)

for i in range(1, 8):
    Pn = legendre(i)
    y = Pn(x)
    plt.plot(x, y, label=f'- n = {i}')

plt.title("Полиномы Лежандра")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()
