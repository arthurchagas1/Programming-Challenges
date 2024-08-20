#include <iostream>

using namespace std;

// Função para calcular o fatorial de um número
long long factorial(int x) {
    long long result = 1;
    for (int i = 2; i <= x; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int M, N;
    
    // Leitura indefinida até o final do arquivo
    while (cin >> M >> N) {
        long long sum_factorials = factorial(M) + factorial(N);
        cout << sum_factorials << endl;
    }

    return 0;
}
