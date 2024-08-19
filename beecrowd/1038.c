#include <stdio.h>
 
int main() {
    float valores[6];
    
    valores[0] = 0.0;
    valores[1] = 4.0;
    valores[2] = 4.5;
    valores[3] = 5.0;
    valores[4] = 2.0;
    valores[5] = 1.5;
    
    int a, b;
    
    scanf("%i %i", &a, &b);
    
    float preco;
    
    preco = valores[a] * b;
    
    printf("Total: R$ %.2f\n", preco);
 
    return 0;
}
