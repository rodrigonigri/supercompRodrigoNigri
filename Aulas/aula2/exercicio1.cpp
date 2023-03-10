#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool my_compare(float a, float b){
    return a < b;
}

void calcula_media(vector<float>& v){ // estamos utilizando & pois estamos fazendo so a leitura do vetor, então nada será alterado!
    float m = 0.0;
    for(auto& e: v){
        m += e;
    }
    cout << "Média = " << m / v.size() << endl;
    v.push_back(0.0);
}

int main(){
    vector<float> nums;
    float num = 0.0;
    cout << "Digite quantos numeros quiser: " << endl;
    while(cin >> num){
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    cout << "Maior = " << nums[nums.size()-1] << endl;
    cout << "Menor = " << nums[0] << endl;

    calcula_media(nums);
    cout << "Tamanho vector: " << nums.size() << endl;
    return 0;
}