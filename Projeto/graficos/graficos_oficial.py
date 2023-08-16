import matplotlib.pyplot as plt
import matplotlib.style as mplstyle
import numpy as np
import pandas as pd
from mpl_toolkits.mplot3d import Axes3D

df = pd.read_excel("resultados.xlsx")

lista_filmes_vistos_aleatoria_array = df["filmesVistosAleatoria"]
lista_filmes_vistos_gulosa_array = df["filmesVistosGulosa"]

lista_tempo_tela_aleatoria_array = df["tempoTelaAleatoria"]
lista_tempo_tela_gulosa_array = df["tempoTelaGulosa"]

lista_media_tempo_tela_aleatoria_array = df["mediaTempoTelaAleatoria"]
lista_media_tempo_tela_gulosa_array = df["mediaTempoTelaGulosa"]

lista_tempo_aleatoria_array = df["temposAleatoria"]
lista_tempo_gulosa_array = df["temposGulosa"]

# printando os tamanhos das listas:
print(len(lista_filmes_vistos_aleatoria_array))
print(len(lista_filmes_vistos_gulosa_array))
print(len(lista_tempo_tela_aleatoria_array))
print(len(lista_tempo_tela_gulosa_array))
print(len(lista_media_tempo_tela_aleatoria_array))
print(len(lista_media_tempo_tela_gulosa_array))
print(len(lista_tempo_aleatoria_array))
print(len(lista_tempo_gulosa_array))



lista_categorias_array = []
lista_total_filmes_array = []


        
for i in range(1, 10000):
    lista_categorias_array.append(1)
    lista_categorias_array.append(2)
    lista_categorias_array.append(3)
    lista_categorias_array.append(4)
    lista_categorias_array.append(5)
    lista_categorias_array.append(6)
    lista_categorias_array.append(7)
    lista_categorias_array.append(8)
    
for i in range(1, 10000):
    lista_total_filmes_array.append(i)
    lista_total_filmes_array.append(i)
    lista_total_filmes_array.append(i)
    lista_total_filmes_array.append(i)
    lista_total_filmes_array.append(i)
    lista_total_filmes_array.append(i)
    lista_total_filmes_array.append(i)
    lista_total_filmes_array.append(i)
    


print(len(lista_total_filmes_array))

# GRAFICOS DE TEMPO: 
'''
# tempo x numero de filmes (gulosa)
fig = plt.figure()
plt.scatter(lista_total_filmes_array, lista_tempo_gulosa_array, label="Heurística Gulosa", color = "blue", alpha = 0.05)
plt.title('Tempo x Número de Filmes')
plt.xlabel('Número de Filmes (#)')
plt.ylabel('Tempo (s)')
plt.legend()
plt.show()

# tempo x numero de filmes (aleatoria):
fig = plt.figure()
plt.scatter(lista_total_filmes_array, lista_tempo_aleatoria_array, label="Heurística Aleatoria", color = "red", alpha = 0.05)
plt.title('Tempo x Número de Filmes')
plt.xlabel('Número de Filmes (#)')
plt.ylabel('Tempo (s)')
plt.legend()
plt.show()

# tempo x numero de filmes (gulosa e aleatoria) 2D
fig = plt.figure()
plt.scatter(lista_total_filmes_array, lista_tempo_gulosa_array, label="Heurística Gulosa", color = "blue", alpha = 0.05)
plt.scatter(lista_total_filmes_array, lista_tempo_aleatoria_array, label="Heurística Aleatória", color = "red", alpha = 0.05)
plt.title('Tempo x Número de Filmes')
plt.xlabel('Número de Filmes (#)')
plt.ylabel('Tempo (s)')
plt.legend()
plt.show()

# tempo x numero de categorias (gulosa)
fig = plt.figure()
plt.scatter(lista_categorias_array , lista_tempo_gulosa_array, label="Heurística Gulosa", color = "blue", alpha = 0.05)
plt.title('Tempo x Número de Categorias')
plt.xlabel('Número de Categorias (#)')
plt.ylabel('Tempo (s)')
plt.legend()
plt.show()

# tempo x numero de categorias (aleatoria)
fig = plt.figure()
plt.scatter(lista_categorias_array , lista_tempo_aleatoria_array, label="Heurística Aleatória", color = "red", alpha = 0.05)
plt.title('Tempo x Número de Categorias')
plt.xlabel('Número de Categorias (#)')
plt.ylabel('Tempo (s)')
plt.legend()
plt.show()

# tempo x numero de categorias (gulosa e aleatoria) 2D
fig = plt.figure()
plt.scatter(lista_categorias_array , lista_tempo_gulosa_array, label="Heurística Gulosa", color = "blue", alpha = 0.05)
plt.scatter(lista_categorias_array , lista_tempo_aleatoria_array, label="Heurística Aleatória", color = "red", alpha = 0.05)
plt.title('Tempo x Número de Categorias')
plt.xlabel('Número de Categorias (#)')
plt.ylabel('Tempo (s)')
plt.legend()
plt.show()
'''

# tempo x numero de filmes x numero de categorias 3D (gulosa)
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(lista_categorias_array, lista_total_filmes_array, lista_tempo_gulosa_array, label="Heurística Gulosa", color = "blue", alpha = 0.05)
ax.set_title('Tempo x Número de Categorias x Número de Filmes')
ax.set_xlabel('Número de Categorias (#)')
ax.set_ylabel('Número de Filmes (#)')
ax.set_zlabel('Tempo (s)')
plt.legend()
plt.show()

# tempo x numero de filmes x numero de categorias 3D (aleatoria)
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(lista_categorias_array, lista_total_filmes_array, lista_tempo_aleatoria_array, label="Heurística Aleatória", color = "red", alpha = 0.05)
ax.set_title('Tempo x Número de Categorias x Número de Filmes')
ax.set_xlabel('Número de Categorias (#)')
ax.set_ylabel('Número de Filmes (#)')
ax.set_zlabel('Tempo (s)')
plt.legend()
plt.show()

# GRAFICOS DE FILMES ASSISTIDOS:

# filmes entrada x filmes assistidos (gulosa)
fig = plt.figure() 
plt.scatter(lista_total_filmes_array, lista_filmes_vistos_gulosa_array, label="Heurística Gulosa", color = "blue", alpha = 0.05)
plt.title('Número de Filmes da Entrada x Número de Filmes Assistidos')
plt.xlabel('Número de Filmes da Entrada (#)')
plt.ylabel('Número de Filmes Assistidos (#)')
plt.legend()
plt.show()

# filmes entrada x filmes assistidos (aleatoria)
fig = plt.figure()
plt.scatter(lista_total_filmes_array, lista_filmes_vistos_aleatoria_array, label="Heurística Aleatória", color = "red", alpha = 0.05)
plt.title('Número de Filmes da Entrada x Número de Filmes Assistidos')
plt.xlabel('Número de Filmes da Entrada (#)')
plt.ylabel('Número de Filmes Assistidos (#)')
plt.legend()
plt.show()

#   filmes entrada x filmes assistidos (gulosa e aleatoria) 2D
fig = plt.figure()
plt.scatter(lista_total_filmes_array, lista_filmes_vistos_gulosa_array, label="Heurística Gulosa", color = "blue", alpha = 0.05)
plt.scatter(lista_total_filmes_array, lista_filmes_vistos_aleatoria_array, label="Heurística Aleatória", color = "red", alpha = 0.05)
plt.title('Número de Filmes da Entrada x Número de Filmes Assistidos')
plt.xlabel('Número de Filmes da Entrada (#)')
plt.ylabel('Número de Filmes Assistidos (#)')
plt.legend()
plt.show()

# categorias entrada x filmes assistidas (gulosa)
fig = plt.figure()
plt.scatter(lista_categorias_array, lista_filmes_vistos_gulosa_array, label="Heurística Gulosa", color = "blue", alpha = 0.05)
plt.title('Número de Categorias da Entrada x Número de Filmes Assistidos')
plt.xlabel('Número de Categorias da Entrada (#)')
plt.ylabel('Número de Filmes Assistidos (#)')
plt.legend()
plt.show()

# categorias entrada x filmes assistidas (aleatoria)
fig = plt.figure()
plt.scatter(lista_categorias_array, lista_filmes_vistos_aleatoria_array, label="Heurística Aleatória", color = "red", alpha = 0.05)
plt.title('Número de Categorias da Entrada x Número de Filmes Assistidos')
plt.xlabel('Número de Categorias da Entrada (#)')
plt.ylabel('Número de Filmes Assistidos (#)')
plt.legend()
plt.show()

# categorias entrada x filmes assistidas (gulosa e aleatoria) 2D
fig = plt.figure()
plt.scatter(lista_categorias_array, lista_filmes_vistos_gulosa_array, label="Heurística Gulosa", color = "blue", alpha = 0.05)
plt.scatter(lista_categorias_array, lista_filmes_vistos_aleatoria_array, label="Heurística Aleatória", color = "red", alpha = 0.05)
plt.title('Número de Categorias da Entrada x Número de Filmes Assistidos')
plt.xlabel('Número de Categorias da Entrada (#)')
plt.ylabel('Número de Filmes Assistidos (#)')
plt.legend()
plt.show()

# filmes assistidos x filmes entrada x categorias entrada 3D (gulosa)
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(lista_categorias_array, lista_total_filmes_array, lista_filmes_vistos_gulosa_array, label="Heurística Gulosa", color = "blue", alpha = 0.05)
ax.set_title('Número de Filmes Assistidos x Número de Categorias x Número de Filmes da Entrada')
ax.set_xlabel('Número de Categorias (#)')
ax.set_ylabel('Número de Filmes (#)')
ax.set_zlabel('Número de Filmes Assistidos (#)')
plt.legend()
plt.show()

# filmes assistidos x filmes entrada x categorias entrada 3D (aleatoria)
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(lista_categorias_array, lista_total_filmes_array, lista_filmes_vistos_aleatoria_array, label="Heurística Aleatória", color = "red", alpha = 0.05)
ax.set_title('Número de Filmes Assistidos x Número de Categorias x Número de Filmes da Entrada')
ax.set_xlabel('Número de Categorias (#)')
ax.set_ylabel('Número de Filmes (#)')
ax.set_zlabel('Número de Filmes Assistidos (#)')
plt.legend()
plt.show()

# HORAS ASSISTIDAS:

# filmes entrada x horas assistidas (gulosa)
fig = plt.figure()
plt.scatter(lista_total_filmes_array, lista_tempo_tela_gulosa_array, label="Heurística Gulosa", color = "blue", alpha = 0.05)
plt.title('Número de Filmes da Entrada x Horas Assistidas')
plt.xlabel('Número de Filmes da Entrada (#)')
plt.ylabel('Horas Assistidas (h)')
plt.legend()
plt.show()

#   filmes entrada x horas assistidas (aleatoria)
fig = plt.figure()
plt.scatter(lista_total_filmes_array, lista_tempo_tela_aleatoria_array, label="Heurística Aleatória", color = "red", alpha = 0.05)
plt.title('Número de Filmes da Entrada x Horas Assistidas')
plt.xlabel('Número de Filmes da Entrada (#)')
plt.ylabel('Horas Assistidas (h)')
plt.legend()
plt.show()

#  filmes entrada x horas assistidas (gulosa e aleatoria) 2D
fig = plt.figure()
plt.scatter(lista_total_filmes_array, lista_tempo_tela_gulosa_array, label="Heurística Gulosa", color = "blue", alpha = 0.05)
plt.scatter(lista_total_filmes_array, lista_tempo_tela_aleatoria_array, label="Heurística Aleatória", color = "red", alpha = 0.05)
plt.title('Número de Filmes da Entrada x Horas Assistidas')
plt.xlabel('Número de Filmes da Entrada (#)')
plt.ylabel('Horas Assistidas (h)')
plt.legend()
plt.show()

# categorias entrada x horas assistidas (gulosa)
fig = plt.figure()
plt.scatter(lista_categorias_array, lista_tempo_tela_gulosa_array, label="Heurística Gulosa", color = "blue", alpha = 0.05)
plt.title('Número de Categorias da Entrada x Horas Assistidas')
plt.xlabel('Número de Categorias da Entrada (#)')
plt.ylabel('Horas Assistidas (h)')
plt.legend()
plt.show()

# categorias entrada x horas assistidas (aleatoria)
fig = plt.figure()
plt.scatter(lista_categorias_array, lista_tempo_tela_aleatoria_array, label="Heurística Aleatória", color = "red", alpha = 0.05)
plt.title('Número de Categorias da Entrada x Horas Assistidas')
plt.xlabel('Número de Categorias da Entrada (#)')
plt.ylabel('Horas Assistidas (h)')
plt.legend()
plt.show()

# categorias entrada x horas assistidas (gulosa e aleatoria) 2D
fig = plt.figure()
plt.scatter(lista_categorias_array, lista_tempo_tela_gulosa_array, label="Heurística Gulosa", color = "blue", alpha = 0.05)
plt.scatter(lista_categorias_array, lista_tempo_tela_aleatoria_array, label="Heurística Aleatória", color = "red", alpha = 0.05)
plt.title('Número de Categorias da Entrada x Horas Assistidas')
plt.xlabel('Número de Categorias da Entrada (#)')
plt.ylabel('Horas Assistidas (h)')
plt.legend()
plt.show()

# horas assistidas x filmes entrada x categorias entrada 3D (gulosa)
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(lista_categorias_array, lista_total_filmes_array, lista_tempo_tela_gulosa_array, label="Heurística Gulosa", color = "blue", alpha = 0.05)
ax.set_title('Horas Assistidas x Número de Categorias x Número de Filmes da Entrada')
ax.set_xlabel('Número de Categorias (#)')
ax.set_ylabel('Número de Filmes (#)')
ax.set_zlabel('Horas Assistidas (h)')
plt.legend()
plt.show()

# horas assistidas x filmes entrada x categorias entrada 3D (aleatoria) 
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(lista_categorias_array, lista_total_filmes_array, lista_tempo_tela_aleatoria_array, label="Heurística Aleatória", color = "red", alpha = 0.05)
ax.set_title('Horas Assistidas x Número de Categorias x Número de Filmes da Entrada')
ax.set_xlabel('Número de Categorias (#)')
ax.set_ylabel('Número de Filmes (#)')
ax.set_zlabel('Horas Assistidas (h)')
plt.legend()
plt.show()





























'''


# GRAFICOS DE TEMPO --------------------------------------------------------------------



# TEMPO X NUMERO DE FILMES E CATEGORIAS (GULOSA) 3D
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')
ax.scatter(l_n_categorias_input, l_n_filmes_input, l_tempos_gulosa,  color='blue')
ax.set_title('Tempo x Número de Categorias e Filmes da Entrada (Heurística Gulosa)')
ax.set_xlabel('Número de Categorias (#)')
ax.set_ylabel('Número de Filmes (#)')
ax.set_zlabel('Tempo (s)')
plt.show()

# TEMPO X NUMERO DE FILMES E CATEGORIAS (ALEATORIA) 3D
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')
ax.scatter(l_n_categorias_input, l_n_filmes_input, l_tempos_aleatoria,  color='red')
ax.set_title('Tempo x Número de Categorias e Filmes da Entrada (Heurística Aleatória)')
ax.set_xlabel('Número de Categorias (#)')
ax.set_ylabel('Número de Filmes (#)')
ax.set_zlabel('Tempo (s)')
plt.show()

# GRAFICOS DE FILMES ASSISTIDOS --------------------------------------------------------------------

# FILMES ENTRADA X FILMES ASSISTIDOS (GULOSA E ALEATORIA) 2D
fig = plt.figure()
plt.scatter(l_n_categorias_input_7000filmes, l_n_filmes_gul_output_7000filmes, label="Heurística Gulosa", color = "blue", alpha = 0.3)
plt.scatter(l_n_categorias_input_7000filmes, l_n_filmes_aleat_output_7000filmes, label="Heurística Aleatória", color = "red", alpha = 0.3)
plt.title('Filmes Entrada x Filmes Assistidos')
plt.xlabel('Filmes da Entrada (#)')
plt.ylabel('Filmes Assistidos (#)')
plt.legend()
plt.show()

fig = plt.figure()
plt.scatter(l_n_filmes_input_cat_5, l_n_filmes_gul_output_cat_5, label="Heurística Gulosa", color = "blue", alpha = 0.3)
plt.title('Filmes Entrada x Filmes Assistidos')
plt.xlabel('Filmes da Entrada (#)')
plt.ylabel('Filmes Assistidos (#)')
plt.legend()
plt.ylim(0, 50)
plt.show()

fig = plt.figure()
plt.scatter(l_n_filmes_input_cat_5, l_n_filmes_aleat_output_cat_5, label="Heurística Aleatória", color = "red", alpha = 0.3)
plt.title('Filmes Entrada x Filmes Assistidos')
plt.xlabel('Filmes da Entrada (#)')
plt.ylabel('Filmes Assistidos (#)')
plt.legend()
plt.ylim(0, 50)
plt.show()

# CATEGORIAS X FILMES ASSISTIDOS (GULOSA E ALEATORIA) 2D
fig = plt.figure()
plt.scatter(l_n_categorias_input, l_n_filmes_gul_output, label="Heurística Gulosa", color = "blue", alpha = 0.3)
plt.scatter(l_n_categorias_input, l_n_filmes_aleat_output, label="Heurística Aleatória", color = "red", alpha = 0.3)
plt.title('Categorias da Entrada x Filmes Assistidos')
plt.xlabel('Categorias (#)')
plt.ylabel('Filmes Assistidos (#)')
plt.legend()
plt.show()

fig = plt.figure()
plt.scatter(l_n_categorias_input, l_n_filmes_gul_output, label="Heurística Gulosa", color = "blue", alpha = 0.3)
plt.scatter(l_n_categorias_input, l_n_filmes_aleat_output, label="Heurística Aleatória", color = "red", alpha = 0.3)
plt.title('Categorias da Entrada x Filmes Assistidos')
plt.xlabel('Categorias (#)')
plt.ylabel('Filmes Assistidos (#)')
plt.legend()
plt.show()

fig = plt.figure()
plt.scatter(l_n_categorias_input, l_n_filmes_gul_output, label="Heurística Gulosa", color = "blue", alpha = 0.3)
plt.title('Categorias da Entrada x Filmes Assistidos')
plt.xlabel('Categorias (#)')
plt.ylabel('Filmes Assistidos (#)')
plt.legend()
plt.show()

fig = plt.figure()
plt.scatter(l_n_categorias_input, l_n_filmes_aleat_output, label="Heurística Aleatória", color = "red", alpha = 0.3)
plt.title('Categorias da Entrada x Filmes Assistidos')
plt.xlabel('Categorias (#)')
plt.ylabel('Filmes Assistidos (#)')
plt.legend()
plt.show()

# FILMES ASSISTIDOS X NUMERO DE FILMES E CATEGORIAS (GULOSA) 3D
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')
ax.scatter(l_n_categorias_input, l_n_filmes_input, l_n_filmes_gul_output,  color='blue')
ax.set_title('Filmes Assistidos x Número de Categorias e Filmes da Entrada (Heurística Gulosa)')
ax.set_xlabel('Número de Categorias (#)')
ax.set_ylabel('Número de Filmes (#)')
ax.set_zlabel('Filmes Assistidos (#)')
plt.show()

# FILMES ASSISTIDOS X NUMERO DE FILMES E CATEGORIAS (ALEATORIA) 3D
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')
ax.scatter(l_n_categorias_input, l_n_filmes_input, l_n_filmes_aleat_output,  color='red')
ax.set_title('Filmes Assistidos x Número de Categorias e Filmes da Entrada (Heurística Aleatória)')
ax.set_xlabel('Número de Categorias (#)')
ax.set_ylabel('Número de Filmes (#)')
ax.set_zlabel('Filmes Assistidos (#)')
plt.show()

# GRAFICOS DE HORAS ASSISTIDAS --------------------------------------------------------------------

# FILMES ENTRADA X HORAS ASSISTIDAS (GULOSA E ALEATORIA) 2D
fig = plt.figure()
plt.scatter(l_n_filmes_input, l_n_horas_gul_output, label="Heurística Gulosa", color = "blue", alpha = 0.3)
plt.scatter(l_n_filmes_input, l_n_horas_aleat_output, label="Heurística Aleatória", color = "red", alpha = 0.3)
plt.title('Filmes Entrada x Horas Assistidas')
plt.xlabel('Filmes da Entrada (#)')
plt.ylabel('Horas Assistidas (h)')
plt.legend()
plt.show()

fig = plt.figure()
plt.scatter(l_n_filmes_input, l_n_horas_gul_output, label="Heurística Gulosa", color = "blue", alpha = 0.3)
plt.title('Filmes Entrada x Horas Assistidas')
plt.xlabel('Filmes da Entrada (#)')
plt.ylabel('Horas Assistidas (h)')
plt.legend()
plt.show()

fig = plt.figure()
plt.scatter(l_n_filmes_input, l_n_horas_aleat_output, label="Heurística Aleatória", color = "red", alpha = 0.3)
plt.title('Filmes Entrada x Horas Assistidas')
plt.xlabel('Filmes da Entrada (#)')
plt.ylabel('Horas Assistidas (h)')
plt.legend()
plt.show()

# CATEGORIAS X HORAS ASSISTIDAS (GULOSA E ALEATORIA) 2D
fig = plt.figure()
plt.scatter(l_n_categorias_input, l_n_horas_gul_output, label="Heurística Gulosa", color = "blue", alpha = 0.3)
plt.scatter(l_n_categorias_input, l_n_horas_aleat_output, label="Heurística Aleatória", color = "red", alpha = 0.3)
plt.title('Categorias da Entrada x Horas Assistidas')
plt.xlabel('Categorias (#)')
plt.ylabel('Horas Assistidas (h)')
plt.legend()
plt.show()

fig = plt.figure()
plt.scatter(l_n_categorias_input, l_n_horas_gul_output, label="Heurística Gulosa", color = "blue", alpha = 0.3)
plt.title('Categorias da Entrada x Horas Assistidas')
plt.xlabel('Categorias (#)')
plt.ylabel('Horas Assistidas (h)')
plt.legend()
plt.show()

fig = plt.figure()
plt.scatter(l_n_categorias_input, l_n_horas_aleat_output, label="Heurística Aleatória", color = "red", alpha = 0.3)
plt.title('Categorias da Entrada x Horas Assistidas')
plt.xlabel('Categorias (#)')
plt.ylabel('Horas Assistidas (h)')
plt.legend()
plt.show()

# HORAS ASSISTIDAS X NUMERO DE FILMES E CATEGORIAS (GULOSA) 3D
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')
ax.scatter(l_n_categorias_input, l_n_filmes_input, l_n_horas_gul_output,  color='blue')
ax.set_title('Horas Assistidas x Número de Categorias e Filmes da Entrada (Heurística Gulosa)')
ax.set_xlabel('Número de Categorias (#)')
ax.set_ylabel('Número de Filmes (#)')
ax.set_zlabel('Horas Assistidas (h)')
plt.show()

# HORAS ASSISTIDAS X NUMERO DE FILMES E CATEGORIAS (ALEATORIA) 3D
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d')
ax.scatter(l_n_categorias_input, l_n_filmes_input, l_n_horas_aleat_output,  color='red')
ax.set_title('Horas Assistidas x Número de Categorias e Filmes da Entrada (Heurística Aleatória)')
ax.set_xlabel('Número de Categorias (#)')
ax.set_ylabel('Número de Filmes (#)')
ax.set_zlabel('Horas Assistidas (h)')
plt.show()
'''