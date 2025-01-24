a = int(input())
b = int(input())
c = int(input())

arr = [a, b, c]
mas = ["a", "b", "c"]

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
if arr[0] == arr[1] and arr[1] == arr[2]:
    print(f'{mas[0]} = {mas[1]} = {mas[2]}')
elif arr[0] == arr[1] and arr[1] < arr[2]:
    print(f'{mas[0]} = {mas[1]} < {mas[2]}')
elif arr[0] < arr[1] and arr[1] == arr[2]:
    print(f'{mas[0]} < {mas[1]} = {mas[2]}')
else:
    print(f'{mas[0]} < {mas[1]} < {mas[2]}')