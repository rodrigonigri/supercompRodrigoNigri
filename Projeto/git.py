import subprocess

for i in range(1, 31):
    for j in range(1, 9):
        filename = f"inputs/input_{i}_filmes_{j}_categorias.txt"
        command = f"git add {filename}"
        subprocess.run(command, shell=True)