#include<iostream>
#include<algorithm>
using namespace std;

constexpr int M = 2048;
constexpr int N = 2048;

double naive_sum(const double a[][N]){ // percorre as colunas externamente e as linhas internamente
    double sum = 0.0;
    for(int j = 0; j < N; ++j) {
        for(int i = 0; i < M; ++i)
            sum += a[i][j];
    }
    return sum;
}

double improved_sum(const double a[][N]) { // percorre as linhas externamente e as colunas internamente
    double sum = 0.0;
    for(int i = 0; i < M; ++i)
        for(int j = 0; j < N; ++j)
            sum +=a[i][j];
    return sum;
}

int main() {
    static double a[M][N];
    fill_n(&a[0][0], M*N, 1.0 / (M*N));
    cout << naive_sum(a) << endl;
    static double b[M][N];
    fill_n(&b[0][0], M*N, 1.0 / (M*N));
    cout << improved_sum(b) << endl;
    return 0;
}
/*
A improved_sum é mais eficiente. Isso se dá devido a forma que a matriz se organiza na RAM. 

[[1,2,3],        A RAM se organiza da seguinte forma:  RAM[1,2,3,4,5,6,7,8,9] e não: RAM[1,4,7,2,5,8,3,6,9]
[4,5,6],
[7,8,9]]

*/