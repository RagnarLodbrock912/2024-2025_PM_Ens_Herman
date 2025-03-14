with open("lab_05/1.in") as file:
    
    array = [row.strip() for row in file]

array = list(map(int, array[0].split()))
s = 1

for i in range(len(array)):
    s *= int(array[i])

with open('lab_05/1.out', 'w') as fil:
    fil.write(str(s))
