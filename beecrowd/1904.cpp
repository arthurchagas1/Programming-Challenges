#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000000

// Função para gerar crivo de Eratóstenes
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

// Função para contar a frequência de um fator p em n!
int count_factors(int n, int p) {
    int count = 0, power = p;
    while (n / p > 0) {
        count += n / p;
        p *= power;
    }
    return count;
}

// Função para verificar se o número de combinações é par ou ímpar
bool is_even(int n, int k) {
    return count_factors(n + k - 1, 2) > count_factors(k, 2) + count_factors(n - 1, 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Gera o crivo de Eratóstenes para encontrar os primos até MAX
    vector<bool> prime_numbers = sieve(MAX);
    
    int A, B;
    cin >> A >> B;

    // Se A é igual a B, a partida empata
    if (A == B) {
        cout << "?\n";
        return 0;
    }

    int lower = min(A, B);
    int upper = max(A, B);
    int num_factors = upper - lower;

    // Conta o número de primos no intervalo [lower, upper]
    int prime_count = 0;
    for (int i = lower; i <= upper; ++i) {
        if (prime_numbers[i]) {
            prime_count++;
        }
    }

    // Determina o vencedor com base na contagem de primos e no número de fatores
    if (prime_count == 0) {
        cout << "Bob\n";
    } else {
        if (is_even(prime_count, num_factors)) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }

    return 0;
}
