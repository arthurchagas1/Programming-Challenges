#include <stdio.h>
 
int main() {
 
    int c, p, f;
    
    scanf("%d%d%d", &c, &p, &f);
    
    int fpc;
    
    fpc = f*c;
    
    if(fpc <= p) {
        puts("S");
    }
    
    else {
        puts("N");
    }
 
    return 0;
}
