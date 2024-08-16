#include <stdio.h>

int main() {
    
    int A, B, C, D, diferenca;
    
    // Leitura dos valores A, B, C e D
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    scanf("%d", &D);
    
    // Cálculo da diferença do produto de A e B pelo produto de C e D
    diferenca = A * B - C * D;
    
    // Impressão da diferença
    printf("DIFERENCA = %d\n", diferenca);
 
    return 0;
}
