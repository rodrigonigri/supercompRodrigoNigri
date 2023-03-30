import subprocess
import time
import os

def roda_com_entrada(executavel, input, heuristica):
    with open(input) as f:
        start = time.perf_counter()
        proc = subprocess.run([executavel], input=f.read(), text=True, capture_output=True)
        end = time.perf_counter()
        
        #print(proc.stdout)
        
    return end-start

lista_t_aleatoria = []
lista_t_gulosa = []

for i in range(1,10000):
    for j in range(1,9):
        
        lista_t_aleatoria.append(roda_com_entrada("/home/user/supercompRodrigoNigri/Projeto/aleatoria/ale_output","inputs/input_" + str(i) + "_filmes_" + str(j) + "_categorias.txt", "output_aleatoria.txt"))
        lista_t_gulosa.append(roda_com_entrada("/home/user/supercompRodrigoNigri/Projeto/gulosa/gul_output","inputs/input_" + str(i) + "_filmes_" + str(j) + "_categorias.txt", "output_gulosa.txt"))
        

with open("tempos_aleatoria.txt", 'w') as f:
    for i in lista_t_aleatoria:
        f.write(str(i))
        f.write('\n')
    
    
with open("tempos_gulosa.txt", 'w') as f:
    for i in lista_t_gulosa:
        f.write(str(i))
        f.write('\n')
    
    
    