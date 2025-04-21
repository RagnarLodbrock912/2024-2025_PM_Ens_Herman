import numpy as np

matrix = []

with open("lab_09/matrix.txt", 'r') as file:
    for line in file:
        row = list(map(float, line.strip().split(',')))
        matrix.append(row)

matrix = np.array(matrix)

print(f'max: {np.max(matrix)}')
print(f'min: {np.min(matrix)}')
print(f'sum: {np.sum(matrix)}')