n = 3
arr = []
mas = ["a", "b", "c"]

for i in range(n): 
    i = int(input())
    arr.append(i)

count = True

while count:
    count = False
    for i in range(2):
        if arr[i] > arr[i + 1]:
            tmp = arr[i]
            arr[i] = arr[i + 1]
            arr[i + 1] = tmp
            temp = mas[i]
            mas[i] = mas[i + 1]
            mas[i + 1] = temp
            count = True
answ = ""
for i in range(n - 1):
    answ += mas[i]
    if arr[i] == arr[i + 1]:
        answ += "="
    if arr[i] < arr[i + 1]:
        answ += "<"
    if arr[i] > arr[i + 1]:
        answ += ">"
answ += mas[n - 1]

print(answ)