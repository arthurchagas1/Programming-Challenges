#include <bits/stdc++.h>
using namespace std;

// Função para gerar a lista de primos até um determinado limite usando o Crivo de Eratóstenes
vector<int> gerarPrimos(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    vector<int> primes;
    for (int p = 2; p <= n; p++) {
        if (prime[p])
            primes.push_back(p);
    }

    return primes;
}

// Função principal para resolver o problema
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    // Limite razoável para a lista de primos
    const int MAX_LIMITE = 2000000;
    vector<int> primos = gerarPrimos(MAX_LIMITE);

    while (T--) {
        int N;
        cin >> N;

        set<long long> numeros_iniciais;
        for (int i = 0; i < N; ++i) {
            long long e;
            cin >> e;
            numeros_iniciais.insert(e);
        }

        long long max_x = 0;
        for (int primo : primos) {
            if (numeros_iniciais.find(primo) == numeros_iniciais.end()) {
                max_x = primo - 1;
                break;
            }
        }
        if (max_x == 6) {
            max_x = 0;
        }
        cout << max_x << '\n';
    }

    return 0;
}
