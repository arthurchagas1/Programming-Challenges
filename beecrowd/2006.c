#include <stdio.h>
 
int main() {
 
    int cha;
    int a, b, c, d, e;
    
    scanf("%i", &cha);
    scanf("%i%i%i%i%i", &a, &b, &c, &d, &e);
    
    int contador;
    
    if (a == cha) contador++;
    if (b == cha) contador++;
    if (c == cha) contador++;
    if (d == cha) contador++;
    if (e == cha) contador++;
    
    printf("%i\n", contador);
    
 
    return 0;
}
