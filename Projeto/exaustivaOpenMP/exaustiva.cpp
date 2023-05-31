#include<iostream>
#include<vector>
#include<algorithm>
#include <random>
#include <stdlib.h>
#include <fstream>
#include<omp.h>
using namespace std;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


struct filme {
    int id;
    int inicio;
    int fim;
    int categoria;
};


int main(){
    int numero_filmes;
    int numero_categorias;
    vector<filme> filmes; // vetor que armazena todos os filmes
    vector<filme> cronograma; // vetor que armazena os filmes que serao vistos no dia
    vector<int> maximo_categorias; // vetor que diz quantos filmes por categoria {'0',3,7,5,2}


    cin >> numero_filmes >> numero_categorias;


    maximo_categorias.push_back(0);

    int max;
    for(int i = 0; i < numero_categorias; i++){
        cin >> max;
        maximo_categorias.push_back(max);
    }

    

    int hora_inicio, hora_fim, cat;

    for(int i = 0; i < numero_filmes; i++){
        cin >> hora_inicio;
        cin >> hora_fim;
        cin >> cat;

        if(hora_fim == 0){
            hora_fim = 24;
        }

        if(hora_fim > hora_inicio){
            filmes.push_back({i, hora_inicio,hora_fim, cat});
        }
    }

    // Função para verificar se o cronograma atual viola as restrições de categorias
    auto verificaRestricoes = [](const vector<filme>& cronograma, const vector<int>& maximo_categorias) {
        vector<int> contador_categorias(maximo_categorias.size(), 0);
        for (const auto& film : cronograma) {
            contador_categorias[film.categoria]++;
        }
        for (size_t i = 1; i < maximo_categorias.size(); i++) {
            if (contador_categorias[i] > maximo_categorias[i]) {
                return false;
            }
        }
        return true;
    };

    vector<filme> melhor_cronograma; // Armazena o melhor cronograma encontrado
    int max_filmes_vistos = 0; // Armazena o número máximo de filmes vistos

    // Percorre todas as combinações possíveis de filmes
    int num_combinacoes = 1 << filmes.size();
    for (int i = 0; i < num_combinacoes; i++) {
        vector<filme> temp_cronograma;
        for (int j = 0; j < (int)filmes.size(); j++) {
            if ((i >> j) & 1) {
                temp_cronograma.push_back(filmes[j]);
            }
        }

        if (verificaRestricoes(temp_cronograma, maximo_categorias)) {
            if ((int)temp_cronograma.size() > max_filmes_vistos) {
                max_filmes_vistos = temp_cronograma.size();
                melhor_cronograma = temp_cronograma;
            }
        }
    }

    // Imprime o melhor cronograma
    cout << "Melhor cronograma:" << endl;
    for (const auto& film : melhor_cronograma) {
        cout << "Filme " << film.id << " - Início: " << film.inicio << " Fim: " << film.fim << " Categoria: " << film.categoria << endl;
    }

    return 0;
}







