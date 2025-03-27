# в файл ex_2.json добалены квадратные скобочки чтобы коореектно считывалось
import json

with open("./lab_07/ex_2.json") as file:
    data = json.load(file)

with open("./lab_07/ex_2_new.json", 'w') as file:
    json.dump(data, file, indent=4)

for user in data:
    print(f"{user['name']}: {user['phoneNumber']}")