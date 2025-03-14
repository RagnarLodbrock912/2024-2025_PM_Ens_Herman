import sys  
from pathlib import Path 

if len(sys.argv) == 1:
    print('No args') 
else: 
    p_name = sys.argv[1]
    dirpath = Path(sys.argv[2])
    t_name = sys.argv[3]
    if p_name == '--dirpath' and t_name == "--files":
        files = sys.argv[4:]
        files_in_dir = [f for f in dirpath.iterdir() if f.is_file()]
        total_size = sum(f.stat().st_size for f in files_in_dir)
        if len(files) == 0:
            print(f"Amount: {len(files_in_dir)}, Total size: {total_size}")
        else:
            exist = []
            nonexist = []
            for i in range(len(files)):
                if Path(f"{dirpath}/{files[i]}") in files_in_dir:
                    exist.append(files[i])
                else:
                    nonexist.append(files[i])
                
            print(f"Nonexist: {nonexist}, Exist: {exist}")
            with open('lab_05/5_e.out', 'w') as fil:
                fil.write("\n".join(exist))

            with open('lab_05/5_n.out', 'w') as fil:
                fil.write("\n".join(nonexist))

    else:
        print('Unknown args') 
