#include <stdio.h>
 
int main() {
 
    int n;
    
    int i = 2;
    int r = 1;
    
    scanf("%d", &n);
    
    while(i <= n) {
        r *= i;
        i++;
    }
    
    printf("%d\n", r);
 
    return 0;
}
