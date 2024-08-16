#include <stdio.h>
 
int main() {
 
    double a;
    int v[12] = {0};
    int valor[12] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
    
    scanf("%lf", &a);
    
    int b = (int)(a * 100);
    
    printf("NOTAS:\n");
    
    for(int i = 0; i < 6; i++) {
        v[i] = b / valor[i];
        b %= valor[i];
    }
    
    printf("%d nota(s) de R$ 100.00\n", v[0]);
    printf("%d nota(s) de R$ 50.00\n", v[1]);
    printf("%d nota(s) de R$ 20.00\n", v[2]);
    printf("%d nota(s) de R$ 10.00\n", v[3]);
    printf("%d nota(s) de R$ 5.00\n", v[4]);
    printf("%d nota(s) de R$ 2.00\n", v[5]);
    
    printf("MOEDAS:\n");
 
    for(int i = 6; i < 12; i++) {
        v[i] = b / valor[i];
        b %= valor[i];
    }
    printf("%d moeda(s) de R$ 1.00\n", v[6]);
    printf("%d moeda(s) de R$ 0.50\n", v[7]);
    printf("%d moeda(s) de R$ 0.25\n", v[8]);
    printf("%d moeda(s) de R$ 0.10\n", v[9]);
    printf("%d moeda(s) de R$ 0.05\n", v[10]);
    printf("%d moeda(s) de R$ 0.01\n", v[11]);
 
    return 0;
}
