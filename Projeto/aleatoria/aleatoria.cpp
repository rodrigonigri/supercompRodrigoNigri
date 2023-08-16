#include<iostream>
#include<vector>
#include<algorithm>
#include <random>
#include <stdlib.h>
#include <fstream>

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

using namespace std;

struct filme {
    int id;
    int inicio;
    int fim;
    int categoria;
};


bool verifica_calendario(filme f, vector<int> v){
    for(int i = f.inicio; i < f.fim; i++){
        if(v.at(i) == 1){
            return false;
        }
    }
    return true;
}

void altera_calendario(filme f, vector<int>& v){
    for(int i = f.inicio; i < f.fim; i++){
        v[i] = true;
    }
}


bool my_compare(filme a, filme b){
    return a.fim < b.fim; // ordenando pelo mais leve
}

void createOutput(int numero_filmes, int tempo_de_tela){
    ofstream output;
    output.open("output_aleatoria.txt", std::ios_base::app);
    output << numero_filmes << " " << tempo_de_tela << " " << (double)tempo_de_tela/numero_filmes << endl;
    output.close();
}

int main(){
    int numero_filmes;
    int numero_categorias;
    vector<filme> filmes; // vetor que armazena todos os filmes
    vector<filme> cronograma; // vetor que armazena os filmes que serao vistos no dia
    vector<int> maximo_categorias; // vetor que diz quantos filmes por categoria {'0',3,7,5,2}
    vector<int> organizador_de_horarios;
    int eliminados = 0; // filmes que o gerador de input gerou que nao se encaixam nas regras do problema.

    // CRIANDO VETOR DE 24 POSICOES TODAS FALSE PARA SABER QUAIS HORARIOS JA FORAM OS FILMES.
    for(int i = 0; i < 24; i++){
        organizador_de_horarios.push_back(false);
    }

    cin >> numero_filmes >> numero_categorias;

    
    maximo_categorias.push_back(0); // so pra ficar alinhado (cat1 na posicao 1, cat2 na posicao 2...)

    
    // CRIANDO O VETOR QUE INDICA QUANTOS FILMES PODE VER POR CATEGORIA
    int max;
    for(int i = 0; i < numero_categorias; i++){
        cin >> max;
        maximo_categorias.push_back(max);

    }

    // CRIANDO O VETOR CONTENDO TODOS OS FILMES, JA DESCARTNDO OS DEPOIS DAS 00:00
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
            eliminados = eliminados + 1;
        }

    }

    numero_filmes = numero_filmes - eliminados;

    sort(filmes.begin(), filmes.end(), my_compare);
    //unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(10); // random com a seed 10

    int i = 1;
    for(auto& this_film : filmes){
        uniform_real_distribution<double> distribution(0.0, 1.0);


        if(verifica_calendario(this_film, organizador_de_horarios) && maximo_categorias[this_film.categoria] > 0){
            cronograma.push_back(this_film);
            altera_calendario(this_film, organizador_de_horarios);
            maximo_categorias[this_film.categoria] -= 1;
        }

        if (distribution(generator) > 0.75 && i < numero_filmes){
            uniform_int_distribution<int> distribution(i, numero_filmes - 1);
            int p = distribution(generator);

            if(verifica_calendario(filmes[p], organizador_de_horarios) && maximo_categorias[this_film.categoria] > 0){
                cronograma.push_back(filmes[p]);
                altera_calendario(filmes[p], organizador_de_horarios);
                maximo_categorias[filmes[p].categoria] -= 1;
                filmes.erase(filmes.begin()+p-1);
                numero_filmes = numero_filmes - 1;
            }
        }

        i += 1;

    }

    int numero_filmes_vistos = 0;
    int tempo_de_tela = 0;
    for(auto& this_film:cronograma){
        numero_filmes_vistos += 1;
        tempo_de_tela += this_film.fim - this_film.inicio;
    }

    createOutput(numero_filmes_vistos, tempo_de_tela);

    

    cout<<"\n\n\n";
    
    cout << "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|00\t01\t02\t03\t04\t05\t06\t07\t08\t09\t10\t11\t12\t13\t14\t15\t16\t17\t18\t19\t20\t21\t22\t23\t|" << endl;
    int agora = 0;
    int numero_de_espacos = 0;
    int numero_de_filme = 0;
    for(auto& this_film : cronograma){
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
                cout << MAGENTA;
            }
            else if (this_film.categoria==7){
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


