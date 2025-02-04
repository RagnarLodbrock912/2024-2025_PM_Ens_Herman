string = input()

symbols = {}

for i in range(len(string)):
    if symbols.get(string[i]) == None and string[i] != ' ':
        symbols[string[i]] = 1
    elif string[i] != ' ':
        symbols[string[i]] += 1

res = sorted(symbols.items(), key=lambda item: item[1], reverse=True)

for i in range(3):
    print(res[i])