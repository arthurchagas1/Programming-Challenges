#include <stdio.h>
 
int main() {
 
    double h, vel;
    double dis;
    
    double comb;
    
    scanf("%lf%lf", &h, &vel);
    
    dis = h*vel;
    
    comb = dis/12;
    
    printf("%.3lf\n", comb);
 
    return 0;
}
