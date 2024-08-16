#include <stdio.h>
 
int main() {
 
    int numero, horas;
    double salario;
    
    scanf("%d", &numero);
    scanf("%d", &horas);
    scanf("%lf", &salario);
    
    printf("NUMBER = %d\n", numero);
    
    double dinheiro;
    dinheiro = horas * salario;
    
    printf("SALARY = U$ %.2lf\n", dinheiro);
    
    
 
    return 0;
}
