#include <stdio.h>
#include <math.h>

int main() {
    double A, B, C;
    double delta, R1, R2;

    // Leitura dos valores de A, B e C
    scanf("%lf %lf %lf", &A, &B, &C);

    // Verificação se é possível calcular
    if (A == 0) {
        printf("Impossivel calcular\n");
    } else {
        delta = B * B - 4 * A * C;

        if (delta < 0) {
            printf("Impossivel calcular\n");
        } else {
            // Cálculo das raízes usando a fórmula de Bhaskara
            R1 = (-B + sqrt(delta)) / (2 * A);
            R2 = (-B - sqrt(delta)) / (2 * A);

            // Impressão dos resultados com 5 casas decimais
            printf("R1 = %.5lf\n", R1);
            printf("R2 = %.5lf\n", R2);
        }
    }

    return 0;
}
