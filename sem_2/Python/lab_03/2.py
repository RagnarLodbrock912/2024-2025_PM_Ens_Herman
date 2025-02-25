n = int(input())

arr = []

for i in range(n):
    a = int(input())
    arr.append(a)

m = int(input())

arr2 = []
count = 0

for i in range(m):
    a = int(input())
    if a in arr:
        count += 1
    arr2.append(a)

print(count)

