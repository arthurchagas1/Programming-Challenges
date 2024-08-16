#include <stdio.h>
#include <stdbool.h>

// Função para verificar se é possível distribuir os presentes sem desequilibrar o trenó
bool canBalance(int N, int presents[]) {
    // Define a capacidade máxima de desequilíbrio como 5kg
    const int MAX_IMBALANCE = 5;
    
    // Inicializa uma matriz para armazenar se é possível alcançar um certo desequilíbrio com os presentes disponíveis
    bool dp[N + 1][2 * MAX_IMBALANCE + 1]; // dp[i][j] representa se é possível alcançar um desequilíbrio de j com os primeiros i presentes
    
    // Inicializa a matriz dp com falsos
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= 2 * MAX_IMBALANCE; j++) {
            dp[i][j] = false;
        }
    }

    // Configura o valor inicial como verdadeiro (desequilíbrio de 0)
    dp[0][MAX_IMBALANCE] = true;

    // Percorre os presentes e atualiza a matriz dp
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 2 * MAX_IMBALANCE; j++) {
            // Verifica se o desequilíbrio j pode ser alcançado com os primeiros i presentes
            if (dp[i - 1][j]) {
                // Adiciona o presente atual ao lado A
                int newImbalanceA = j + presents[i - 1];
                if (newImbalanceA <= 2 * MAX_IMBALANCE) {
                    dp[i][newImbalanceA] = true;
                }
                // Adiciona o presente atual ao lado B
                int newImbalanceB = j - presents[i - 1];
                if (newImbalanceB >= 0) {
                    dp[i][newImbalanceB] = true;
                }
            }
        }
    }

    // Verifica se é possível alcançar um desequilíbrio dentro da capacidade máxima
    for (int j = 0; j <= MAX_IMBALANCE; j++) {
        if (dp[N][MAX_IMBALANCE + j] || dp[N][MAX_IMBALANCE - j]) {
            return true;
        }
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        int presents[N];

        // Leitura dos pesos dos presentes
        for (int i = 0; i < N; i++) {
            scanf("%d", &presents[i]);
        }

        // Verifica se é possível distribuir os presentes sem desequilibrar o trenó
        if (canBalance(N, presents)) {
            printf("Feliz Natal!\n");
        } else {
            printf("Ho Ho Ho!\n");
        }
    }

    return 0;
}

