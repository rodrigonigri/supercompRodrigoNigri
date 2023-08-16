import pandas


# create dataframe
df_aleatoria = pandas.DataFrame(columns=['numero_filmes_vistos', 'tempo_de_tela', 'media_tempo_filmes'])

# read output_aleaoria.txt line by line
with open('output_aleatoria.txt') as f:
    
	# read line by line
	for line in f:
		
		# split line by space
		line = line.split()
		
		# append to dataframe
		df = df.append({'numero_filmes_vistos': line[0], 'tempo_de_tela': line[1], 'media_tempo_filmes': line[2]}, ignore_index=True)

# create dataframe
df_gulosa = pandas.DataFrame(columns=['numero_filmes_vistos', 'tempo_de_tela', 'media_tempo_filmes'])

# read output_aleaoria.txt line by line
with open('output_gulosa.txt') as f:
    
	# read line by line
	for line in f:
		
		# split line by space
		line = line.split()
		
		# append to dataframe
		df = df.append({'numero_filmes_vistos': line[0], 'tempo_de_tela': line[1], 'media_tempo_filmes': line[2]}, ignore_index=True)
