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

bool my_compare(item a, item b){
    return a.peso < b.peso; // ordenando pelo mais leve
}

int main() {
    int n = 0;
    int W = 0;
    vector<item> mochila;
    vector<item> items;
    vector<item> items2;
    cin >> n >> W;
    items.reserve(n); // ja reserva na memoria o tamanho para nao ficar fazendo push back
    double peso, valor;
    for(int i = 0; i < n; i++){
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }
    //ordenar
    //sort(items.begin(), items.end(), my_compare);
    peso = 0;
    valor = 0;
    default_random_engine generator(10); // random com a seed 10

    for(auto& this_item : items){
        uniform_real_distribution<double> distribution(0.0, 1.0);
        //distribution(generator); // gera número

        if (distribution(generator) > 0.5 && this_item.peso + peso <= W){ // coloca o elemento na mochila
            mochila.push_back(this_item);
            peso += this_item.peso;
            valor += this_item.valor;
            
        }
        else{
            items2.push_back(this_item);
        }
        
    }

    for(auto& this_item: items){
        cout << "id:" << this_item.id << " peso:" << this_item.peso << " valor:" << this_item.valor << endl;
    }

    cout << endl;

    //ordenando para imprimir
    for(auto& this_item: mochila){
        cout << "id:" << this_item.id << " peso:" << this_item.peso << " valor:" << this_item.valor << endl;
    }

    cout << endl;
    
    for(auto& this_item : items2){
        //distribution(generator); // gera número

        if (this_item.peso + peso <= W){ // coloca o elemento na mochila
            mochila.push_back(this_item);
            peso += this_item.peso;
            valor += this_item.valor;
        }
        
    }

    for(auto& this_item: items2){
        cout << "id:" << this_item.id << " peso:" << this_item.peso << " valor:" << this_item.valor << endl;
    }

    cout << endl;

    //ordenando para imprimir
    for(auto& this_item: mochila){
        cout << "id:" << this_item.id << " peso:" << this_item.peso << " valor:" << this_item.valor << endl;
    }

    return 0;
}