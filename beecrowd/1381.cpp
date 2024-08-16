#include <iostream>
using namespace std;

const int MOD = 1300031;

// Função para calcular o fatorial de um número com módulo
long long factorial(int num) {
    long long result = 1;
    for (int i = 2; i <= num; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

// Função para calcular o inverso modular usando a exponenciação rápida
long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Aplicação do Algoritmo de Euclides Estendido
    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Função para calcular a combinação C(n, k) módulo MOD
long long combination(int n, int k) {
    if (k > n) return 0;
    long long num = factorial(n);
    long long denom = (factorial(k) * factorial(n - k)) % MOD;
    return (num * modInverse(denom, MOD)) % MOD;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, C;
        cin >> N >> C;
        cout << combination(N + C - 1, C) << endl;
    }
    
    return 0;
}
