n = int(input())

arr = []

for i in range(n):
    a = int(input())
    arr.append(a)

res = []

res.append(arr[0])

for i in range(n - 1):
    if(arr[i + 1] > arr[i]):
        res.append(arr[i + 1])

print(res)