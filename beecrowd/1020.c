#include <stdio.h>
 
int main() {
 
    int a;
    
    scanf("%d", &a);
    
    int ano, mes, dia;
    
    ano = a / 365;
    
    int temp = a % 365;
    
    mes = temp / 30;
    
    temp = temp % 30;
    
    dia = temp;
    
    printf("%d ano(s)\n", ano);
    printf("%d mes(es)\n", mes);
    printf("%d dia(s)\n", dia);
 
    return 0;
}
