import numpy as np

a = np.array([0,1,2,0,0,4,0,6,9])

idx = np.nonzero(a)

print(idx[0])