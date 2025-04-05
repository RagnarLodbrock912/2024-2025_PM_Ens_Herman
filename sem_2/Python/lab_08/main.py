import csv
import random
import os


class CSVReader:


    def __init__(self, path_to_file: str) -> None:
        self.file_path = path_to_file

    def Show(self, output_type: str ="top", amount_of_rows: int = 5, separator: str = ",") -> None:
        with open(self.file_path, newline='', encoding='utf-8') as file:
            reader = list(csv.reader(file))
        
        data = [row for row in reader if any(row)]  

        if not data:
            print("No data in file")
            return
        
        if output_type not in ["top", "bottom", "random"]:
            print("Invalid output_type. Use 'top', 'bottom', or 'random'.")
            return
    
        size_of_columns = [0] * len(data[0])

        for i in range(len(data)):
            for j in range(len(data[0])):
                if len(data[i][j]) > size_of_columns[j]:
                    size_of_columns[j] = len(data[i][j])

        table = list()

        for i in range(len(data)):
            current_row = str()
            for j in range(len(data[0])):
                if j == len(data[0]) - 1:
                    current_row += data[i][j] + " " * (size_of_columns[j] - len(data[i][j]))
                else:
                    current_row += data[i][j] + " " * (size_of_columns[j] - len(data[i][j])) + separator + " "
            table.append(current_row)


        # print top of table
        print(table[0])
        print("-" * (sum(size_of_columns) + 2 * len(data[0]) - 4))

        total_rows = len(table) - 1
        table = table[1:]

        # print rows
        if output_type == "top":
            rows_to_print = min(amount_of_rows, total_rows)
            for i in range(rows_to_print):
                print(table[i])
            if total_rows < amount_of_rows:
                print("Not enough rows")
        
        elif output_type == "bottom":
            rows_to_print = min(amount_of_rows, total_rows)
            for i in range(total_rows - rows_to_print, total_rows):
                print(table[i])
            if total_rows < amount_of_rows:
                print("Not enough rows")

        elif output_type == "random":
            random_rows = random.sample(table, min(amount_of_rows, len(table) - 1))
            for row in random_rows:
                print(row)
            if len(table) - 1 < amount_of_rows:
                print("Not enough rows")

    def Info(self) -> None:
        with open(self.file_path, mode='r', encoding='utf-8', newline='') as f:
            reader = csv.DictReader(f)
            rows = list(reader)

        if not rows:
            print("0x0")
            return

        num_rows = len(rows)
        fieldnames = reader.fieldnames
        num_cols = len(fieldnames)
        print(f"{num_rows}x{num_cols}")

        max_field_len = max(len(field) for field in fieldnames)
        FIELD_WIDTH = max(max_field_len, 12) + 2
        COUNT_WIDTH = 5
        TYPE_WIDTH = 10

        print(f"{'Field Name':{FIELD_WIDTH}}{'Count':>{COUNT_WIDTH}}  {'Type':<{TYPE_WIDTH}}")
        print("-" * (FIELD_WIDTH + COUNT_WIDTH + TYPE_WIDTH))

        for field in fieldnames:
            values = [row[field].strip() for row in rows if row[field].strip() != ""]
            count_non_empty = len(values)

            inferred_type = 'string'
            if values:
                if all(v.isdigit() for v in values):
                    inferred_type = 'int'
                else:
                    try:
                        [float(v) for v in values]
                        inferred_type = 'float'
                    except ValueError:
                        inferred_type = 'string'

            print(f"{field:{FIELD_WIDTH}}{count_non_empty:>{COUNT_WIDTH}}  {inferred_type:<{TYPE_WIDTH}}")

    def DelNaN(self):
        with open(self.file_path, newline='', encoding='utf-8') as file:
            reader = list(csv.reader(file))
        
        data = [row for row in reader if any(row)]  

        if not data:
            print("No data in file")
            return
        
        new_data = list()

        for i in range(len(data)):
            flag = True
            for j in range(len(data[0])):
                if data[i][j] == '':
                    flag = False
            
            if flag:
                new_data.append(data[i])

        data = new_data

        with open(self.file_path, mode="w", newline='', encoding="utf-8") as file:
            writer = csv.writer(file)
            writer.writerows(data)
        
    def MakeDS(self) -> None:
        with open(self.file_path, newline='', encoding='utf-8') as file:
            reader = list(csv.reader(file))
        
        data = [row for row in reader if any(row)]  

        if not data:
            print("No data in file")
            return

        folder_path = os.path.dirname(self.file_path)

        os.makedirs(f"{folder_path}/workdata", exist_ok=True)
        os.makedirs(f"{folder_path}/workdata/Learning", exist_ok=True)
        os.makedirs(f"{folder_path}/workdata/Testing", exist_ok=True)

        header = data[0]
        data = data[1:]
        
        random.shuffle(data)

        split_index = int(len(data) * 0.7)
        train = data[:split_index]
        test = data[split_index:]

        with open(f"{folder_path}/workdata/Learning/train.csv", mode="w", newline='', encoding="utf-8") as file:
            writer = csv.writer(file)
            writer.writerow(header)
            writer.writerows(train)

        with open(f"{folder_path}/workdata/Testing/test.csv", mode="w", newline='', encoding="utf-8") as file:
            writer = csv.writer(file)
            writer.writerow(header)
            writer.writerows(test)

    
reader = CSVReader("lab_08/Employees.csv")
# reader.Show("top", 5, ",")
# print("\n\n")
# reader.Show("bottom", 5, "|")
# print("\n\n")
# reader.Show("random", 5, "|")
# print("\n\n")
# reader.Show("top", 10, "|")
# print("\n\n")
# reader.DelNaN()
# reader.Show("top", 10, "|")
# reader.Info()
reader.MakeDS()
