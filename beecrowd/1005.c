#include <stdio.h>
 
int main() {
 
    double A, B, media;
    
    // Leitura das notas A e B
    scanf("%lf", &A);
    scanf("%lf", &B);
    
    // Cálculo da média ponderada
    media = (A * 3.5 + B * 7.5) / 11.0;
    
    // Impressão da média com 5 dígitos após o ponto decimal
    printf("MEDIA = %.5lf\n", media);
 
    return 0;
 
}
