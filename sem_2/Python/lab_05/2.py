with open("lab_05/2.in") as file:
    
    array = [int(row.strip()) for row in file]

array.sort()

array = list(map(str, array))

with open('lab_05/2.out', 'w') as fil:
    fil.write("\n".join(array))
