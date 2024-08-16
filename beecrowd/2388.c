#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // Leitura do número de intervalos

    int tempo, velocidade_media;
    long long distancia_total = 0; // Usando long long para evitar estouro

    // Leitura dos intervalos e cálculo da distância total
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &tempo, &velocidade_media);
        distancia_total += (long long)tempo * velocidade_media;
    }

    // Impressão do resultado
    printf("%lld\n", distancia_total);

    return 0;
}
