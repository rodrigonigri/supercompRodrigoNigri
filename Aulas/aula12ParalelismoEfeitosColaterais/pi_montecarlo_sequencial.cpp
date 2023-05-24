#include<iostream>
#include<vector>
#include<algorithm>
#include <random>
#include <stdlib.h>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
    int sum = 0;
    int n;
    double x = 0;
    double y = 0;

    default_random_engine generator(10);
    

    cout << "digite um n para calcular montecarlo:" << endl;

    cin >> n;

    for(int i = 0; i < n; i++){
        uniform_real_distribution<double> distribution(0.0, 1.0);
        x = distribution(generator);
        y = distribution(generator);


        if(pow(x,2) + pow(y,2) <= 1){
            sum += 1;
        }

    }
    double result = 4 * sum / (double) n ;
    cout << result << endl;

    return 0;
}