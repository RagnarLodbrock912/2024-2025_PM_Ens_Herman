with open("lab_05/3.in") as file:
    
    array = [row.strip() for row in file]

for i in range(len(array)):
    array[i] = array[i].split()
    array[i][2] = int(array[i][2])

array.sort(key = lambda x: x[2])
print(array)

with open('lab_05/3_y.out', 'w') as fil:
    fil.write("".join(str(array[0])))

with open('lab_05/3_e.out', 'w') as fil:
    fil.write("".join(str(array[len(array) - 1])))
