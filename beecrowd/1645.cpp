#include <iostream>
#include <vector>
using namespace std;

long long contar_subsequencias_crescentes(int n, int k, const vector<int>& numeros) {
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

    // Caso base: uma subsequência de tamanho 1 é sempre crescente
    for (int i = 0; i <= n; ++i) {
        dp[i][1] = 1;
    }

    // Preenche a tabela dp
    for (int i = 2; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int l = 1; l < j; ++l) {
                if (numeros[l - 1] < numeros[j - 1]) {
                    dp[j][i] += dp[l][i - 1];
                }
            }
        }
    }

    // Soma todas as contagens das subsequências de tamanho k
    long long total = 0;
    for (int i = k; i <= n; ++i) {
        total += dp[i][k];
    }

    return total;
}

int main() {
    int n, k;
    while (cin >> n >> k && (n != 0 || k != 0)) {
        vector<int> numeros(n);
        for (int i = 0; i < n; ++i) {
            cin >> numeros[i];
        }

        long long resultado = contar_subsequencias_crescentes(n, k, numeros);
        cout << resultado << endl;
    }

    return 0;
}
