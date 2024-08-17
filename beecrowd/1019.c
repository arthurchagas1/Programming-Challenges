#include <stdio.h>
 
int main() {
    int a;
    
    scanf("%i", &a);
    
    int seg, min, h;
    
    h = a / 3600;
    
    min = (a%3600) / 60;
    
    seg = a%60;
    
    printf("%i:%i:%i\n", h, min, seg);
 
    return 0;
}
