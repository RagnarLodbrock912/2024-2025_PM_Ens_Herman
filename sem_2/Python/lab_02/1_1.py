string = input()
answ = ""

i = 0
while (i < len(string) - 1):
    if string[i + 1].isalpha():
        answ += string[i]
        i -= 1
    else:
        for j in range(int(string[i + 1])):
            answ += string[i]
    i += 2

if (string[len(string) - 1].isalpha()):
    answ += string[len(string) - 1]

print(answ)