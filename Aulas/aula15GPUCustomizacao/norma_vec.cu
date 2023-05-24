#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/generate.h>
#include <thrust/functional.h>
#include <thrust/copy.h>
//INSIRA AS IMPORTACOES NECESSARIAS DA THRUST
#include <cmath>
#include <random>

//using namespace std::chrono;

//void reportTime(const char* msg, steady_clock::duration span) {
//    auto ms = duration_cast<milliseconds>(span);
//    std::cout << msg << " - levou - " <<  ms.count() << " milisegundos" << std::endl;
//}

 // CRIE UMA FUNCTOR PARA CALCULAR A SQUARE

struct square 
{
   // const float a;
   // square(float _a): a(_a) {}
    __host__ __device__ // roda tanto na GPU quanto na CPU
    int operator()(int& x) {
        return x * x;
    }
};


 // IMPLEMENTE O CALCULO DA MAGNITUDE COM THRUST
float magnitude(thrust::device_vector<int> vec) {
    float result;
    // ... add Thrust calls
    // AQUI VAO AS CHAMADAS THRUST
    thrust::device_vector<int> squared(vec.size()); 
    
    // chamar square
    thrust::transform(vec.begin(), vec.end(), squared.begin(), square());
    
    // fazer um reduce de soma
    result = sqrt(thrust::reduce(squared.begin(), squared.end(), (int)0, thrust::plus<int>()));

    return result;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << argv[0] << ": numero invalido de argumentos\n"; 
        std::cerr << "uso: " << argv[0] << "  tamanho do vetor\n"; 
        return 1;
    }
    int n = std::atoi(argv[1]); //numero de elementos
    //steady_clock::time_point ts, te;

    // Faça um  vector em thrust 
    thrust::host_vector<int> d(n);
    


    // inicilize o  vector
    //ts = steady_clock::now();

    std::generate(d.begin(),d.end(), std::rand);

    thrust::device_vector<int> d_d = d;


    //te = steady_clock::now();
    //reportTime("Inicializacao", te - ts);

    // Calcule a magnitude do vetor
    //ts = steady_clock::now();
    float len = magnitude(d_d);
    //te = steady_clock::now();
    //reportTime("Tempo para calculo", te - ts);


    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Magnitude : " << len << std::endl;
}
