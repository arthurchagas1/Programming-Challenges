#include <stdio.h>
 
int main() {
 
    int n;
    
    scanf("%d", &n);
    
    int vetor[n];
    int contador = 0;
    
    int i = 1;
    
    while (i <= n) {
        if(n%i == 0) {
            vetor[contador] = i;
            contador++;
        }
        i++;
    }
    
    for (int i = 0; i < contador; i++) {
        printf("%d\n", vetor[i]);
    }
    
    return 0;
}
