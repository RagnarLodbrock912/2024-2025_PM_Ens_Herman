import sys  
from pathlib import Path 

if len(sys.argv) == 1:
    print('No args') 
else: 
    p_name = sys.argv[1]
    dirpath = Path(sys.argv[2])
    if p_name == '--dirpath':
        with open("lab_05/5_n.out") as file:
            files = [row.strip() for row in file]
        print(files)
        for i in range(len(files)):
            with open(Path(dirpath/files[i]), 'a'):
                pass
    else:
        print('Unknown args') 