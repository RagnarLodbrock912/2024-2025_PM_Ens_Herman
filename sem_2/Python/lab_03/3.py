n = int(input())

arr = {}

for i in range(n):
    a = input()
    if arr.get(a) == None:
        arr[a] = 1
    else:
        arr[a] += 1

res = ""
for key, value in arr.items():
    res += f'{str(value)} '

print(res)