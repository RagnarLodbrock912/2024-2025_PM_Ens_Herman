import shutil

terminal_width = shutil.get_terminal_size().columns

n = int(input())

old = ['1']
new = []

for i in range(n):
    curr = " ".join(old)
    print(curr.center(terminal_width))
    new.append('1')
    for j in range(len(old) - 1):
        new.append(str(int(old[j]) + int(old[j + 1])))
    old = new.copy()
    old.append('1')
    new.clear()
