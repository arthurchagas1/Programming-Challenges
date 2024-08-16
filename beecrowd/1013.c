#include <stdio.h>

// Função que recebe três valores e retorna o maior entre eles
int encontra_maior(int a, int b, int c) {
    // Calcula o maior entre a e b usando a fórmula fornecida
    int maior_ab = (a + b + abs(a - b)) / 2;
    
    // Calcula o maior entre o resultado anterior e c
    int maior = (maior_ab + c + abs(maior_ab - c)) / 2;
    
    return maior;
}

int main() {
    int a, b, c;

    // Lê os três valores inteiros
    scanf("%d %d %d", &a, &b, &c);

    // Chama a função para encontrar o maior valor
    int maior = encontra_maior(a, b, c);

    // Imprime o resultado
    printf("%d eh o maior\n", maior);

    return 0;
}
