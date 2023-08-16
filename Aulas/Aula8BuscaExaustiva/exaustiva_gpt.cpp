#include<iostream>
#include<vector>
#include<algorithm>
#include <random>
using namespace std;

int n; // número de itens
int W; // capacidade da mochila
vector<int> wt, val; // pesos e valores dos itens
int maxVal; // valor máximo encontrado

void knapsack(int i, int curW, int curVal) {
    if (i == n) {
        maxVal = max(maxVal, curVal);
    return;
    }
    if (curW + wt[i] <= W) {
    knapsack(i + 1, curW + wt[i], curVal + val[i]);
}
    knapsack(i + 1, curW, curVal);
}

int main() {
    cin >> n >> W;
    wt.resize(n);
    val.resize(n);
    for (int i = 0; i < n; i++) {
    cin >> wt[i] >> val[i];
}
    maxVal = 0;
    knapsack(0, 0, 0);
    cout << maxVal << endl;
    return 0;
}