arr = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

count = 0

for i in range(len(arr)):
    if arr[i] in arr2:
        count += 1

print(count)

