#include <iostream>
#include <algorithm>

using namespace std;

// Função para calcular o MDC de dois números
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Função para simplificar a fração
void simplify(int& num, int& den) {
    int divisor = gcd(abs(num), abs(den));
    num /= divisor;
    den /= divisor;
}

// Função principal para processar os casos de teste
void processTestCases(int n) {
    for (int i = 0; i < n; ++i) {
        int n1, d1, n2, d2;
        char op, slash1, slash2;
        
        // Leitura da entrada
        cin >> n1 >> slash1 >> d1 >> op >> n2 >> slash2 >> d2;

        int num_res, den_res;

        // Realizando a operação de acordo com o operador
        switch (op) {
            case '+':
                num_res = n1 * d2 + n2 * d1;
                den_res = d1 * d2;
                break;
            case '-':
                num_res = n1 * d2 - n2 * d1;
                den_res = d1 * d2;
                break;
            case '*':
                num_res = n1 * n2;
                den_res = d1 * d2;
                break;
            case '/':
                num_res = n1 * d2;
                den_res = n2 * d1;
                break;
        }

        // Resultado antes da simplificação
        cout << num_res << "/" << den_res << " = ";

        // Simplificação da fração
        simplify(num_res, den_res);

        // Resultado após a simplificação
        cout << num_res << "/" << den_res << endl;
    }
}

int main() {
    int n;
    cin >> n;
    processTestCases(n);
    return 0;
}
