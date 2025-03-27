import json

with open("./lab_07/ex_3.json") as file:
    data = json.load(file)

new_data = {
        "id": 3,
        "total": 150.00,
        "items": [
            {
                "name": "item 4",
                "quantity": 3,
                "price": 50.00
            }
        ]
    }

data['invoices'].append(new_data)

with open("./lab_07/ex_3_new.json", 'w') as file:
    json.dump(data, file, indent=4)