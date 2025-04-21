import numpy as np

matrix = np.random.normal(loc=0.0, scale=1.0, size=(10, 4))

new_matrix = matrix[:5]

print(f'max: {np.max(matrix)}')
print(f'min: {np.min(matrix)}')
print(f'mean: {matrix.mean()}')
print(f'std: {matrix.std()}')

print(new_matrix)