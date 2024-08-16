#include <stdio.h>
#include <string.h>
#define MAX 100
 
int main() {
    
    char nome[MAX];
    double salario;
    double vendas;
    
    scanf("%s", nome);
    scanf("%lf", &salario);
    scanf("%lf", &vendas);
    
    double total;
    double vendas_1;
    
    vendas_1 = vendas * 0.15;
    total = salario + vendas_1;
    
    printf("TOTAL = R$ %.2lf\n", total);
 
    return 0;
}
