#include <stdio.h>
 
int par (int n) {
    if (n%2 == 0) {
        return 1;
    }
    
    else return 0;
} 
 
int main() {
 
    int a, b, c, d;
    
    scanf("%d%d%d%d", &a, &b, &c, &d);
    
    if (b > c && d > a && (c + d) > (a + b) && c > 0 && d > 0 && par(a)) {
        puts("Valores aceitos");
    }
    
    else puts("Valores nao aceitos");
 
    return 0;
}
