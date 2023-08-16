#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>
using namespace std;

int main(){
    thrust::host_vector<double> host(5,0);
    host[4] = 35;

    thrust::device_vector<double> dev(host); // move para gpu
    host[2] = 12; // alterou o vetor so na CPU 
    //dev[2] = 12; altera na GPU
    printf("Host vector: ");
    for(auto i = host.begin(); i != host.end(); i++){
        cout << *i << " "; //pointer
    }

    printf("\n");
    printf("Device vector: ");

    for(auto i = dev.begin(); i != dev.end(); i++){ // NAO RECOMENDADO PERCORRER ITEM POR ITEM NA GPU --> melhor trazer de volta para a CPU
        cout << *i << " ";
    }

    return 0;
}