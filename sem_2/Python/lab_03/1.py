n = int(input())
max_ind = 0
min_ind = 0
max = float('-inf')
min = float('inf')
arr = []

for i in range(n):
    a = int(input())
    if a > max:
        max = a
        max_ind = i
    if a < min:
        min = a
        min_ind = i
    arr.append(a)

tmp = arr[max_ind]
arr[max_ind] = arr[min_ind]
arr[min_ind] = tmp

print(arr)