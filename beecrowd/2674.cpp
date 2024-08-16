#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>  // Para std::find

using namespace std;

// Função para determinar se um número é primo usando o Crivo de Eratóstenes
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

// Função para verificar se todos os dígitos de um número são primos
bool are_all_digits_prime(int num, const vector<bool>& is_prime) {
    vector<int> prime_digits = {2, 3, 5, 7};
    while (num > 0) {
        int digit = num % 10;
        if (find(prime_digits.begin(), prime_digits.end(), digit) == prime_digits.end()) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int max_n = 100000;
    vector<bool> is_prime = sieve_of_eratosthenes(max_n);

    int N;
    while (cin >> N) {
        if (!is_prime[N]) {
            cout << "Nada" << endl;
        } else if (are_all_digits_prime(N, is_prime)) {
            cout << "Super" << endl;
        } else {
            cout << "Primo" << endl;
        }
    }

    return 0;
}

