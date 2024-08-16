#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Projetil {
    int poder_destruicao;
    int peso;
};

bool cmp(Projetil a, Projetil b) {
    return a.peso < b.peso;
}

int maximo_dano(int capacidade_carga, int resistencia_castelo, vector<Projetil>& projeteis) {
    int dp[capacidade_carga + 1];
    fill(dp, dp + capacidade_carga + 1, 0);

    for (int i = 0; i < projeteis.size(); ++i) {
        for (int j = capacidade_carga; j >= projeteis[i].peso; --j) {
            dp[j] = max(dp[j], dp[j - projeteis[i].peso] + projeteis[i].poder_destruicao);
        }
    }

    return dp[capacidade_carga] >= resistencia_castelo ? dp[capacidade_carga] : -1;
}

int main() {
    int casos_teste;
    cin >> casos_teste;

    while (casos_teste--) {
        int N, K, R;
        cin >> N;

        vector<Projetil> projeteis(N);
        for (int i = 0; i < N; ++i) {
            cin >> projeteis[i].poder_destruicao >> projeteis[i].peso;
        }

        cin >> K >> R;

        sort(projeteis.begin(), projeteis.end(), cmp);

        int dano_total = maximo_dano(K, R, projeteis);

        if (dano_total >= 0) {
            cout << "Missao completada com sucesso" << endl;
        } else {
            cout << "Falha na missao" << endl;
        }
    }

    return 0;
}

