#include <iostream>
#include <string>
#include <cmath>

const int MOD = 1000000007;

// Função auxiliar para calcular a soma dos dígitos de 1 até n
long long sum_of_digits(long long n) {
    if (n < 10) {
        return n * (n + 1) / 2;
    }

    std::string s = std::to_string(n);
    int length = s.size();
    int first_digit = s[0] - '0';
    long long rest = std::stoll(s.substr(1));

    long long sum_rest = (first_digit * sum_of_digits(std::stoll(std::string(length - 1, '9')))) % MOD;
    long long sum_first = (first_digit * (first_digit - 1) / 2 * (long long)pow(10, length - 1)) % MOD;
    long long sum_remaining = (first_digit * (rest + 1)) % MOD;
    long long sum_all = (sum_rest + sum_first + sum_remaining + sum_of_digits(rest)) % MOD;

    return sum_all;
}

// Função para calcular a soma dos dígitos de L até R
long long sum_of_digits_in_range(long long L, long long R) {
    if (L > R) return 0;

    long long sum_until_R = sum_of_digits(R);
    long long sum_until_L_minus_1 = sum_of_digits(L - 1);

    return (sum_until_R - sum_until_L_minus_1 + MOD) % MOD;
}

int main() {
    long long L, R;
    while (std::cin >> L >> R) {
        std::cout << sum_of_digits_in_range(L, R) << std::endl;
    }
    return 0;
}
