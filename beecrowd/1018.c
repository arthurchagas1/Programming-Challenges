#include <stdio.h>

int main () {
    int a;
    
    scanf("%d", &a);
    
    int cem, cinq, vint, dez, cinc, dois, um;
    
    cem = a / 100;
    
    cinq = (a % 100) / 50;
    
    int temp = (a % 100) % 50;
    
    vint = temp / 20;
    
    temp = temp % 20;
    
    dez = temp / 10;
    
    temp = temp % 10;
    
    cinc = temp / 5;
    
    temp = temp % 5;
    
    dois = temp / 2;
    
    temp = temp % 2;
    
    um = temp;
    
    printf("%d\n", a);
    
    printf("%d nota(s) de R$ 100,00\n", cem);
    printf("%d nota(s) de R$ 50,00\n", cinq);
    printf("%d nota(s) de R$ 20,00\n", vint);
    printf("%d nota(s) de R$ 10,00\n", dez);
    printf("%d nota(s) de R$ 5,00\n", cinc);
    printf("%d nota(s) de R$ 2,00\n", dois);
    printf("%d nota(s) de R$ 1,00\n", um);
    
}
