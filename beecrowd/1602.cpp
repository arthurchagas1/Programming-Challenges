#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Função para calcular todos os números primos até max_n usando o Crivo de Eratóstenes
vector<bool> sieve_of_eratosthenes(int max_n) {
    vector<bool> is_prime(max_n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= max_n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= max_n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return is_prime;
}

// Função para calcular o número de divisores de cada número até max_n
vector<int> count_divisors(int max_n) {
    vector<int> divisors_count(max_n + 1, 0);
    for (int i = 1; i <= max_n; i++) {
        for (int j = i; j <= max_n; j += i) {
            divisors_count[j]++;
        }
    }
    return divisors_count;
}

// Função para pré-computar o número de hiperprimos até max_n
vector<int> precompute_hyperprimes(int max_n) {
    vector<bool> is_prime = sieve_of_eratosthenes(max_n);
    vector<int> divisors_count = count_divisors(max_n);
    vector<int> hyperprime_count(max_n + 1, 0);

    for (int i = 2; i <= max_n; i++) {
        if (is_prime[divisors_count[i]]) {
            hyperprime_count[i] = hyperprime_count[i - 1] + 1;
        } else {
            hyperprime_count[i] = hyperprime_count[i - 1];
        }
    }
    return hyperprime_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int max_n = 2 * 1000000;
    vector<int> hyperprime_count = precompute_hyperprimes(max_n);

    int N;
    while (cin >> N) {
        cout << hyperprime_count[N] << endl;
    }

    return 0;
}
