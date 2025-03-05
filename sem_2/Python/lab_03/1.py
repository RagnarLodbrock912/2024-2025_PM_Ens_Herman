max_ind = 0
min_ind = 0
max = float('-inf')
min = float('inf')
arr = list(map(int, input().split()))

for i in range(len(arr)):
    if arr[i] > max:
        max = arr[i]
        max_ind = i
    if arr[i] < min:
        min = arr[i]
        min_ind = i

arr[max_ind] = min
arr[min_ind] = max

print(arr)