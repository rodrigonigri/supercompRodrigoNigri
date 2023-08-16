#include<iostream>
#include<vector>
#include<algorithm>
#include <random>
#include <stdlib.h>
#include <fstream>
#include<omp.h>
#include <cmath>
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
            filmes.push_back({i, hora_inicio, hora_fim, cat});
        }
    }

    // Create the organizador_de_horarios vector
    vector<bool> organizador_de_horarios(24, false);

    int max_num_filmes = 0;
    vector<filme> melhor_cronograma;

    double start_time = omp_get_wtime();

    // Generate all possible combinations of movies
    for(int i = 0; i < pow(2, filmes.size()); i++){
        vector<filme> opcao_cronograma; // vetor temporário para armazenar a opção de cronograma atual

        for(int j = 0; j < filmes.size(); j++){
            // Check if j-th movie is selected in the current combination
            if(i & (1 << j)){
                opcao_cronograma.push_back(filmes[j]); // Adicionar o filme ao cronograma atual
            }
        }

        // Verificar se a opção de cronograma atual é válida
        bool valido = true;
        vector<int> contador_categorias(numero_categorias + 1, 0); // Vetor para contar o número de filmes por categoria

        for(int j = 0; j < opcao_cronograma.size(); j++){
            int categoria = opcao_cronograma[j].categoria;
            contador_categorias[categoria]++; // Incrementar o contador de filmes para a categoria atual

            // Verificar se o número de filmes para a categoria atual excede o limite
            if(contador_categorias[categoria] > maximo_categorias[categoria]){
                valido = false;
                break;
            }

            // Verificar se há sobreposição de horários
            for(int k = opcao_cronograma[j].inicio; k < opcao_cronograma[j].fim; k++){
                if(organizador_de_horarios[k]){
                    valido = false;
                    break;
                }
            }

            // Alterar o vetor de organização de horários para a próxima iteração
            for(int k = opcao_cronograma[j].inicio; k < opcao_cronograma[j].fim; k++){
                organizador_de_horarios[k] = true;
            }
        }

        if(valido){
            // Atualizar o melhor cronograma encontrado até agora
            if(opcao_cronograma.size() > max_num_filmes){
                max_num_filmes = opcao_cronograma.size();
                melhor_cronograma = opcao_cronograma;
            }
        }

        // Resetar o vetor de organização de horários para a próxima iteração
        for(int j = 0; j < opcao_cronograma.size(); j++){
            for(int k = opcao_cronograma[j].inicio; k < opcao_cronograma[j].fim; k++){
                organizador_de_horarios[k] = false;
            }
        }
    }

    double end_time = omp_get_wtime();
    


    cout<<"\n\n\n";
    cout << "O tempo para encontrar a solução foi:" << end_time - start_time << endl;
    
    cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|00\t01\t02\t03\t04\t05\t06\t07\t08\t09\t10\t11\t12\t13\t14\t15\t16\t17\t18\t19\t20\t21\t22\t23\t|" << endl;
    int agora = 0;
    int numero_de_espacos = 0;
    int numero_de_filme = 0;
    for(auto& this_film : melhor_cronograma){
        agora = this_film.inicio;
        numero_de_espacos = agora;
        numero_de_filme = this_film.fim - this_film.inicio;
        for(int i = 0; i<numero_de_espacos; i++){
            cout<<"\t";
        }

        for(int i = 0; i<numero_de_filme; i++){
            if(this_film.categoria==1){
                cout << RED;
            }
            else if (this_film.categoria==2){
                cout << GREEN;
            }
            else if (this_film.categoria==3){
                cout << MAGENTA;
            }
            else if (this_film.categoria==4){
                cout << YELLOW;
            }
            else if (this_film.categoria==5){
                cout << BLUE;
            }
            else if (this_film.categoria==6){
                cout << CYAN;
            }
            else{
                cout << RESET;
            }
            
            cout<<"|"<<"|"<<"|"<<"|"<<"|"<<"|"<<"|"<<"|";
            cout << RESET;
        }
        cout<<endl;
        
    }
    cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;

    return 0;
}







