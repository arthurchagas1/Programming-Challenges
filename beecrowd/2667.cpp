#include <stdio.h>

int main() {
    char string[150];
    int retorno = 0;
    unsigned short i;

    // Lê o número como uma string
    scanf("%s", string);

    // Calcula N % 3
    for (i = 0; string[i]; ++i) {
        retorno = ((retorno * 10) + (string[i] - '0')) % 3;
    }

    // Determina qual número o primeiro jogador deve escolher
    if (retorno == 0) {
        printf("0\n");  // Não é possível vencer
    } else if (retorno == 1) {
        printf("1\n");  // Começar com 1 para vencer
    } else {
        printf("2\n");  // Começar com 2 para vencer
    }

    return 0;
}
