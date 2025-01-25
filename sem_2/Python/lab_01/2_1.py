n = int(input())
res = ""
arr = []

for i in range(1, n + 1):
    res += str(i)
    arr.append(res)

for elem in reversed(arr):
    print(elem)