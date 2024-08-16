#include <stdio.h>
#include <math.h>

#define PI 3.14159
 
int main() {
 
    double a, b, c;
    
    scanf("%lf%lf%lf", &a, &b, &c);
    
    double tri, cir, tra, qua, ret;
    
    tri = a*c*(0.5);
    
    cir = PI * pow(c, 2);
    
    tra = (a+b)*c*(0.5);
    
    qua = pow(b, 2);
    
    ret = a*b;
    
    printf("TRIANGULO: %.3lf\n", tri);
    printf("CIRCULO: %.3lf\n", cir);
    printf("TRAPEZIO: %.3lf\n", tra);
    printf("QUADRADO: %.3lf\n", qua);
    printf("RETANGULO: %.3lf\n", ret);
    
    
 
    return 0;
}
