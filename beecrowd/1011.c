#include <stdio.h>
#include <math.h>
#define PI 3.14159
 
int main() {
    double raio;
    
    scanf("%lf", &raio);
    
    double vol;
    
    vol = (4.0/3)*PI*pow(raio, 3);
    
    printf("VOLUME = %.3lf", vol);
    
    printf("\n");
    

    return 0;
}
