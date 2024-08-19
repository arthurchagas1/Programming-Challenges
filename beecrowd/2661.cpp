#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Função para fatorar um número e retornar os fatores primos distintos
vector<long long> fatoracaoPrimos(long long n) {
    vector<long long> primos;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            primos.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        primos.push_back(n);
    }
    return primos;
}

// Função para contar todos os divisores despojados
long long contarDivisoresDespojados(long long n) {
    vector<long long> primos = fatoracaoPrimos(n);
    int k = primos.size();
    long long contador = 0;

    // Gerar todos os subconjuntos de primos (exceto conjuntos com menos de dois elementos)
    for (int i = 1; i < (1 << k); i++) {
        long long produto = 1;
        int bits = __builtin_popcount(i); // Conta o número de bits ativos em i
        if (bits > 1) { // Consideramos apenas subconjuntos com dois ou mais primos
            for (int j = 0; j < k; j++) {
                if (i & (1 << j)) {
                    produto *= primos[j];
                }
            }
            if (n % produto == 0) {
                contador++;
            }
        }
    }

    return contador;
}

int main() {
    long long N;
    cin >> N;

    long long resultado = contarDivisoresDespojados(N);

    cout << resultado << endl;

    return 0;
}
