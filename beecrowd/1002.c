#include <stdio.h>
#define PI 3.14159
#include <math.h>

 
int main() {
    double raio;
    
    scanf("%lf", &raio);
    
    double area;
    
    area = PI*pow(raio,2);
    
    printf("A=%.4lf", area);
    
    printf("\n");
    return 0;
}
