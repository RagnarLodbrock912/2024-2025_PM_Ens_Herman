arr = list(map(int, input().split()))

res = []

res.append(arr[0])

for i in range(len(arr) - 1):
    if(arr[i + 1] > arr[i]):
        res.append(arr[i + 1])

print(res)