#include <stdio.h>
#include <string.h>

int count_possible_positions(char *ciphertext, char *crib) {
    int count = 0;
    int ciphertext_length = strlen(ciphertext);
    int crib_length = strlen(crib);

    for (int i = 0; i <= ciphertext_length - crib_length; i++) {
        int possible = 1;
        for (int j = 0; j < crib_length; j++) {
            if (ciphertext[i + j] == crib[j]) {
                possible = 0;
                break;
            }
        }
        if (possible) {
            count++;
        }
    }
    return count;
}

int main() {
    char ciphertext[100005];
    char crib[100005];

    // Leitura da entrada
    scanf("%s", ciphertext);
    scanf("%s", crib);

    // Contagem de posições possíveis
    int result = count_possible_positions(ciphertext, crib);

    // Saída
    printf("%d\n", result);

    return 0;
}
