#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool my_compare(float a, float b);

int main(){
    vector<float> nums;
    nums.push_back(10.5);
    nums.push_back(4.0);

    for(auto& e: nums){ // o "&" significa que ao alterar a variavel e, o valor sera alterado dentro de nums. (isso faz ficar mais rapido!)
                        // como estamos fazendo só leitura, podemos fazer assim. Se quisessemos alterar e sem alterar nums, tirar o "&".
        cout << e << "\t";
    }
    sort(nums.begin(), nums.end(), my_compare); // sort ordena o vetor. (inicio, fim, criterio: funcao que compara)
    
    cout << "\n ORDENADO!" << endl;

    for(auto& e: nums){ 
        cout << e << "\t";
    }

    return 0;
}

    

bool my_compare(float a, float b){
    return a < b;
}
