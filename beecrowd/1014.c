#include <stdio.h>
 
int main() {
 
    int x;
    double y;
    
    scanf("%d", &x);
    scanf("%lf", &y);
    
    double total;
    
    total = x/y;
    
    printf("%.3f km/l\n", total);
    
    return 0;
}
