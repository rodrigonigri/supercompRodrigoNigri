#include <chrono>
#include <random>
#include <fstream>
#include <boost/random.hpp>

using namespace std;

int gerador_inputs(int n_filmes, int n_categorias) {
    
    /* Opening a file and writing the number of movies and categories. */
    ofstream inputFile;
    inputFile.open("input_" + to_string(n_filmes) +"_filmes_" + to_string(n_categorias) + "_categorias" + ".txt");
    inputFile << n_filmes << " " << n_categorias << endl;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);

    uniform_int_distribution<int> distribution(0, 10);

    int random = distribution(generator);

    // Definindo distribuição normal com média de 3 e desvio padrão de 1
    normal_distribution<double> distribution_dif(3, 1.0);

    uniform_int_distribution<int> distribution_hr(0, 23);
    uniform_int_distribution<int> distribution_cat(1, n_categorias);

    vector<int> maxFilmes(n_categorias); // Vetor para armazenar o máximo de filmes por categoria
    for (int i = 0; i < n_categorias; i++) {
        maxFilmes[i] = distribution_cat(generator) + random; // Gerando o máximo de filmes para cada categoria
        inputFile << maxFilmes[i] << " "; // Escrevendo o valor no arquivo de entrada
    }
    inputFile << endl;

    for (int i = 0; i < n_filmes; i++) {
        int hora_inicio = distribution_hr(generator);
        double dif_media = distribution_dif(generator);
        int hora_fim = ((int)hora_inicio + (int)round(dif_media)) % 24;
        int categoria = distribution_cat(generator);

        inputFile << hora_inicio << " " << hora_fim << " " << categoria << endl;
    }


    inputFile.close();
    return 0;
}

int main(){
    int n_filmes = 10000;
    int n_categorias = 9;
    for(int i = 1; i < n_filmes; i++){
        for (int j = 1; j < n_categorias; j++){
            gerador_inputs(i,j);
        }
    }

    return 0;
}