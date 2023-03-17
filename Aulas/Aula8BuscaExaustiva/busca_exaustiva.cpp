#include<iostream>
#include<vector>
#include<algorithm>
#include <random>
using namespace std;

struct item {
    int id;
    double peso;
    double valor;
};

int func_mochila(int capacidade, vector<item> items, vector<item> usados, vector<item> melhor){
    int valor, valor_com_i, valor_sem_i;
    valor_com_i = 0;
    valor_sem_i = 0;
    if(capacidade == 0 || items.empty() == true){
        return 0;
    }

    int this_value = items[0].valor;
    int this_weigth = items[0].peso;
    
    items.erase(items.begin()); // tira o pimeiro item
    valor_sem_i = func_mochila();
    if(capacidade - this_weigth >=0){
        valor_com_i = func_mochila();
    }
    
    
    
    valor = max(valor_com_i, valor_sem_i);
    return valor;
    

}

int main() {
    int n = 0;
    int W = 0;
    vector<item> mochila;
    vector<item> items;
    cin >> n >> W;
    items.reserve(n); // ja reserva na memoria o tamanho para nao ficar fazendo push back
    double peso, valor;
    for(int i = 0; i < n; i++){
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }

    int output = func_mochila(items, W);

    cout << output << endl;
}