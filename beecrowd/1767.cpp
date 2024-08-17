#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct stc {
    int value = 0;  // Quantidade de brinquedos
    int packs = 0;  // Número de pacotes usados
};

stc t[301][51];  // Tabela para a programação dinâmica
stc a, b;  // Variáveis temporárias para armazenar estados

int maximumWeight, qtdPacks;

// Função para resolver o problema da mochila
stc knapsack(int weight[], int value[], int arraySize, int maximumWeight) {
    // Inicializar a primeira linha da tabela
    for (int col = 0; col <= maximumWeight; col++) {
        t[0][col].value = 0;
        t[0][col].packs = 0;  // Inicializar pacotes também
    }

    // Preenchendo a tabela para cada pacote disponível
    for (int i = 1; i <= arraySize; i++) {
        for (int col = 0; col <= maximumWeight; col++) {
            a = t[i - 1][col];  // Estado sem incluir o pacote atual

            if (weight[i] > col) {
                b = t[i - 1][col];  // Não pode incluir o pacote atual
            } else {
                b = t[i - 1][col - weight[i]];  // Inclui o pacote atual
                b.value += value[i];  // Adiciona o valor do pacote
                b.packs++;  // Conta o pacote incluído
            }

            if (a.value >= b.value) {
                t[i][col] = a;  // Prefere a solução sem o pacote atual
            } else {
                t[i][col] = b;  // Prefere a solução com o pacote atual
            }
        }
    }

    return t[arraySize][maximumWeight];  // Retorna a melhor solução
}

// Função para encontrar o peso correspondente ao melhor valor
int findBestWeight(int arraySize, int maximumWeight) {
    int best = -1, pos = 0;

    for (int weight = 1; weight <= maximumWeight; weight++) {
        if (t[arraySize][weight].value > best) {
            best = t[arraySize][weight].value;
            pos = weight;
        }
    }

    return pos;
}

int main() {
    int testCases;

    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        qtdPacks = 0;

        cin >> maximumWeight;

        int weight[maximumWeight + 1]; weight[0] = 0;
        int value[maximumWeight + 1]; value[0] = 0;

        for (int i = 1; i <= maximumWeight; i++) {
            cin >> value[i] >> weight[i];
        }

        stc ans = knapsack(weight, value, maximumWeight, 50);

        cout << ans.value << " brinquedos\n";

        int bestWeight = findBestWeight(maximumWeight, 50);

        cout << "Peso: " << bestWeight << " kg\n";
        cout << "sobra(m) " << maximumWeight - ans.packs << " pacote(s)\n\n";
    }

    return 0;
}
