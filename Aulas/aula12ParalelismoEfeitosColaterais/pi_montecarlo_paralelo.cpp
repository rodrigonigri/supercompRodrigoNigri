#include<iostream>
#include<vector>
#include<algorithm>
#include <random>
#include <stdlib.h>
#include <fstream>
#include<omp.h>
using namespace std;

int main(){
    long sum = 0;
    long n;
    double x = 0;
    double y = 0;
    int n_threads = omp_get_max_threads();

    cout << n_threads << endl;

    vector<default_random_engine> generator_vec;

    for(int i = 0; i < n_threads; i++){
        default_random_engine generator(i);
        generator_vec.push_back(generator);
    }


    cout << "digite um n para calcular montecarlo:" << endl;

    cin >> n;

    #pragma omp parallel for reduction(+:sum)
        for(int i = 0; i < n; i++){
            uniform_real_distribution<double> distribution(0.0, 1.0);

            x = distribution(generator_vec[omp_get_thread_num()]);
            y = distribution(generator_vec[omp_get_thread_num()]);
            


            if(x*x + y*y <= 1){
                sum += 1;
            }

    }
    
    
    double result = 4 * sum / (double) n ;
    cout << result << endl;

    return 0;
}

