dict = {'Hello' : 'Hi', 'Bye' : 'Goodbye', 'List' : 'Array'}

value1 = input()

for key, value in dict.items():
    if value == value1:
        print(key)
