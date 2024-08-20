#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX_R = 300;
const int MAX_C = 300;
int qtd[MAX_R][MAX_C][MAX_C + 1];

// Função para ler a matriz de assentos
void readSeats(int R, vector<string>& seats) {
    for (int i = 0; i < R; ++i) {
        cin >> seats[i];
    }
}

// Função para calcular a matriz 'qtd' que armazena as somas acumuladas de assentos disponíveis
void calculateQtd(int R, int C, const vector<string>& seats) {
    for (int i = R - 1; i >= 0; --i) {
        for (int j = C - 1; j >= 0; --j) {
            for (int size = 1; size <= C - j; ++size) {
                bool available = seats[i][j] == '.';
                qtd[i][j][size] = size == 1 ? available : available + qtd[i][j + 1][size - 1];
            }
        }
    }
}

// Função para encontrar a menor área que contém exatamente K assentos disponíveis
int findMinArea(int R, int C, int K) {
    int minArea = INT_MAX;

    for (int j = 0; j < C; ++j) {
        for (int size = 1; size <= C - j; ++size) {
            int u = 0, availableSeats = 0;

            for (int i = 0; i < R; ++i) {
                availableSeats += qtd[i][j][size];
                
                while (availableSeats >= K) {
                    int area = size * (i - u + 1);
                    minArea = min(minArea, area);
                    availableSeats -= qtd[u++][j][size];
                }
            }
        }
    }

    return minArea;
}

// Função principal que coordena as etapas do processo
int main() {
    int R, C, K;
    
    while (cin >> R >> C >> K && (R || C || K)) {
        vector<string> seats(R);
        readSeats(R, seats);
        
        calculateQtd(R, C, seats);
        
        int minArea = findMinArea(R, C, K);
        
        cout << minArea << endl;
    }

    return 0;
}
