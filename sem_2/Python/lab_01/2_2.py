import shutil

terminal_width = shutil.get_terminal_size().columns

n = int(input())
res = "1"
arr = []
arr.append((n - 1)*" " + res + (n - 1)*" ")

for i in range(2, n + 1):
    res =  str(i) + res + str(i)
    arr.append((n - i)*" " + res  + (n - i)*" ")

for elem in reversed(arr):
    print(elem.center(terminal_width))