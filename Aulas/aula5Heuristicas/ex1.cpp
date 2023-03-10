#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

struct item{
        int indice;
        int peso;
        int valor;
    };

bool my_compare(item a, item b){
    return a.valor < b.valor;
}

int main(){
    
    
    int tamanho, peso_max;


    vector<item> items;


    cin >> tamanho >> peso_max;

    int i = 0;
    while(i < tamanho){
        item item_local;
        cin >> item_local.peso >> item_local.valor;
        item_local.indice = i;
        items.push_back(item_local);
        cout << "saiu" << item_local.peso << endl;
        i++;
    }
    
    sort(items.begin(), items.end(), my_compare);

    for (auto &i : items){
        cout << "valor= " << i.valor << " peso= " << i.peso << " indice= " << i.indice << endl;
    }

    //cout << "saiu" << x << endl;

    return 0;
}
