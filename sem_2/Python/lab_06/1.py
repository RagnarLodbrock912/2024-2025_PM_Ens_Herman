import json

with open("lab_06/Sample-JSON-file-with-multiple-records.json") as file:
    tables = json.load(file)

for table in tables:
    csv = ""
    flag = False
    for data in tables[table]:
        for column in data:
            if not flag:
                csv += f'"{column}",' 
            else:
                csv += f'"{data[column]}",'
        flag = True
        csv = csv.rstrip(",") 
        csv += "\n"
    with open (f"lab_06/{table}.csv", 'w') as file:
        file.write(csv)

