from pathlib import Path 
import shutil

dir = input()

if not dir:
    dir = Path.cwd()
else:
    dir = Path(dir)

files_s = [f for f in dir.iterdir() if f.is_file() and (f.stat().st_size / 1024) <= 2]

if not files_s:
    print("There are no such files")
else:
    target_folder = dir / "small"
    target_folder.mkdir(parents=True, exist_ok=True)

    for file in files_s:
        target_path = target_folder / file.name
        shutil.copy(file, target_path)  