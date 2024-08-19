#include <stdio.h>

int main() {

    double n1, n2, n3, n4;
    
    scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
    
    double media = (2*n1 + 3*n2 + 4*n3 + 1*n4) / 10.0;
    
    printf("Media: %.1f\n", media);
    
    if(media >= 7.0) {
        printf("Aluno aprovado.\n");
    }
    else if(media < 5.0) {
        printf("Aluno reprovado.\n");
    }
    else {
        printf("Aluno em exame.\n");
        double exame;
        scanf("%lf", &exame);
        printf("Nota do exame: %.1f\n", exame);
        double media2 = (media + exame) / 2.0;
        
        if(media2 >= 5.0) {
            printf("Aluno aprovado.\n");
        } else {
            printf("Aluno reprovado.\n");
        }
        
        printf("Media final: %.1f\n", media2);
    }

    return 0;
}
