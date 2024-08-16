#include <stdio.h>
#include <math.h>

int quadrado(int i) {
    return pow(i, 2);
}

int cubo(int i) {
    return pow(i, 3);
}

int main() {
 
   int n;
   
   scanf("%d", &n);
   
   for(int i = 1; i <= n; i++) {
       printf("%d %d %d\n", i, quadrado(i), cubo(i));
   }
 
    return 0;
}
