#include <stdio.h>
#include <math.h>
 
int main() {
    int a, b;
    
    scanf("%d%d", &a, &b);
    
    int c = (int) ceil((double) b / (b - a));
 
    printf("%d\n", c);
 
    return 0;
}
