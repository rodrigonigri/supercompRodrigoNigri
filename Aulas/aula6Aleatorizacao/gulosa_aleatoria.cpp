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
    cin >> n >> W;
    items.reserve(n); // ja reserva na memoria o tamanho para nao ficar fazendo push back
    double peso, valor;
    for(int i = 0; i < n; i++){
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }
    //ordenar
    sort(items.begin(), items.end(), my_compare);
    peso = 0;
    valor = 0;
    default_random_engine generator(10); // random com a seed 10

    int i = 1;
    for(auto& el : items){
        uniform_real_distribution<double> distribution(0.0, 1.0);
        //distribution(generator); // gera número

        if(el.peso + peso <= W){
            mochila.push_back(el);
            peso += el.peso;
            valor += el.valor;
        }

        if (distribution(generator) > 0.75 && i < n){
            uniform_int_distribution<int> distributionInt(i, n-1);
            int p = distributionInt(generator);

            if (items[p].peso + peso <= W){
                mochila.push_back(items[p]);
                peso = peso + items[p].peso;
                valor = valor + items[p].valor;
                items.erase(items.begin()+p-1);
                n = n - 1;
            }
        }

        i = i + 1;
    }
    //ordenando para imprimir
    sort(mochila.begin(), mochila.end(), [](auto& i, auto&j){return i.id < j.id;});
    cout << peso << " " << valor << " 0" << endl;
    for(auto& el: mochila){
        cout << el.id << " ";
    }

    return 0;
}