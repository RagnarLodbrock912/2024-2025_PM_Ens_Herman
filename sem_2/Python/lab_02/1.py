string = input()
answ = ""
count = 1
for i in range(len(string)):
    if i + 1 == len(string):
        answ += string[i] + str(count)
    elif string[i] == string[i + 1]:
        count += 1
    else:
        answ += string[i] + str(count)
        count = 1
print(answ)