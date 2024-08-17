#include <stdio.h>

int main() {
    double F1, F2, flutuacao_total;

    // Leitura dos valores F1 e F2
    scanf("%lf %lf", &F1, &F2);

    // Calcular a flutuação total do PIB
    flutuacao_total = ((1 + F1 / 100) * (1 + F2 / 100) - 1) * 100;

    // Imprimir o resultado com 6 casas decimais
    printf("%.6lf\n", flutuacao_total);

    return 0;
}
