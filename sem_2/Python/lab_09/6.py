import numpy as np

a = np.arange(16).reshape(4,4)

print(a)

i, j = 1, 3
a[[i, j]] = a[[j, i]]

print(a)