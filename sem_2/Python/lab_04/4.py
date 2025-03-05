seq = input()

dct = {}

for i in range(len(seq)):
    if dct.get(int(seq[i])) == None:
        dct[int(seq[i])] = 0
    dct[int(seq[i])] += 1

dct = sorted(dct.items(), key=lambda item: item[1], reverse=True)

print(dict(dct[:3]))

