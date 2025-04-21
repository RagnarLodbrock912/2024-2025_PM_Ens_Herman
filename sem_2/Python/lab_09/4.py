import numpy as np

x = np.array([6, 2, 0, 3, 0, 0, 5, 7, 0]) 

zero_indices = np.where(x == 0)[0]

after_zero_indices = zero_indices + 1
after_zero_indices = after_zero_indices[after_zero_indices < len(x)]

after_zero_values = np.array([x[i] for i in after_zero_indices ])

print(np.max(after_zero_values))