#include<iostream>
using namespace std;

int sqr_it(int x); // avisa o programa que existe essa funcão será ainda definida

int main(){
    int t = 10;
    cout << "o endereço de t = " << &t << endl;
    cout << sqr_it(t) << endl; // t é parâmetro
    return 0;
}

int sqr_it(int x){ // x é argumento
    cout << "o endereço de x = " << &x << endl;
    return x*x;
}