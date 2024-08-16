#include <stdio.h>

int main() {
    // Variáveis para o número inicial de abas, número de ações e contador de abas
    int N, M, abas;

    // Leitura da entrada
    scanf("%d %d", &N, &M);

    // Loop para processar cada ação
    for (int i = 0; i < M; i++) {
        char acao[10];
        scanf("%s", acao);

        // Verifica se a ação foi "fechou" e atualiza o número de abas
        if (acao[0] == 'f') {
            N++;  // Cada vez que Péricles fecha uma aba, duas abas aparecem
        } else {
            N--;  // Cada vez que Péricles clica em uma propaganda, uma aba é fechada
        }
    }

    // Saída do número final de abas
    printf("%d\n", N);

    return 0;
}
