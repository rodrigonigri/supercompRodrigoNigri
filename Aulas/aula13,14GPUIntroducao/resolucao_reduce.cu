#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    thrust::host_vector<double> vcpu(2518);
    for(int i = 0; i < 2518; i++){
        std::cin >> vcpu[i];
    }

    thrust::device_vector<double> vgpu(vcpu);
    double media = thrust::reduce(vgpu.begin(), vgpu.end(), (double)0, thrust::plus<double>()) / vgpu.size();
    std::cout << "Média dos elementos é igual a: " << media << std::endl;


    thrust::device_vector<double>::iterator last_365 = vgpu.end() - 365; //criando um iterator que armazena um endereço de memória
    double media365 = thrust::reduce(last_365, vgpu.end(), (double)0, thrust::plus<double>()) / 365; 
    std::cout << "Média dos últimos 365 elementos é igual a: " << media365 << std::endl;


    thrust::device_vector<double>::iterator max_elem = thrust::max_element(vgpu.begin(), vgpu.end()); //armazenando em max_elem o endereco de memoria do maior elemento do vetor
    thrust::device_vector<double>::iterator min_elem = thrust::min_element(vgpu.begin(), vgpu.end()); //armazenando em min_elem o endereco de memoria do menor elemento do vetor
    std::cout << "Maior elemento é: " << *max_elem << std::endl;
    std::cout << "Menor elemento é: " << *min_elem << std::endl;


    thrust::device_vector<double>::iterator max_elem365 = thrust::max_element(last_365, vgpu.end()); //armazenando em max_elem o endereco de memoria do maior elemento do vetor
    thrust::device_vector<double>::iterator min_elem365 = thrust::min_element(last_365, vgpu.end()); //armazenando em min_elem o endereco de memoria do menor elemento do vetor
    std::cout << "Maior elemento do último ano é: " << *max_elem365 << std::endl;
    std::cout << "Menor elemento do último ano é: " << *min_elem365 << std::endl;

    return 0;
}