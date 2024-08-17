#include <stdio.h>

int count_carry_operations(int a, int b) {
    int carry = 0;
    int carry_operations = 0;

    while (a > 0 || b > 0) {
        // Obter o último dígito de cada número
        int digit_a = a % 10;
        int digit_b = b % 10;

        // Soma dos dígitos e carry anterior
        if (digit_a + digit_b + carry >= 10) {
            carry_operations++;
            carry = 1;
        } else {
            carry = 0;
        }

        // Remover o último dígito dos números
        a /= 10;
        b /= 10;
    }

    return carry_operations;
}

int main() {
    int a, b;

    while (1) {
        // Ler os dois números
        scanf("%d %d", &a, &b);

        // Se os dois números forem 0, terminar o loop
        if (a == 0 && b == 0) {
            break;
        }

        // Contar as operações de carry
        int carries = count_carry_operations(a, b);

        // Imprimir o resultado adequado
        if (carries == 0) {
            printf("No carry operation.\n");
        } else {
            printf("%d carry operation%s.\n", carries, carries > 1 ? "s" : "");
        }
    }

    return 0;
}
