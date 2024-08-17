#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CampoMinado {
public:
    int x1, y1, x2, y2, N;
    vector<pair<int, int>> minas;

    // Construtor do campo minado
    CampoMinado(int X1, int Y1, int X2, int Y2, int num_minas)
        : x1(X1), y1(Y1), x2(X2), y2(Y2), N(num_minas) {}

    // Função para adicionar uma mina no campo
    void adicionarMina(int x, int y) {
        minas.push_back({x1, y});
        minas.push_back({x, y});
    }

    // Função para calcular o maior retângulo seguro
    pair<int, int> encontrarMaiorRegiaoSegura() {
        minas.push_back({x1, y1});
        minas.push_back({x2, y2});
        sort(minas.begin(), minas.end());

        int A = 0, B = 0;

        for (size_t i = 0; i < minas.size() - 1; ++i) {
            int wmin = y2;
            int wmax = y1;
            int x = minas[i].first, y = minas[i].second;
            bool limite = false;

            for (size_t j = i + 1; j < minas.size(); ++j) {
                if (x == minas[j].first) continue;

                int dx = minas[j].first - x;
                int dy = limite ? max(wmin - y, y - wmax) : wmin - wmax;
                int a = min(dx, dy), b = max(dx, dy);

                if (A < a || (A == a && B < b)) {
                    A = a;
                    B = b;
                }

                if (minas[j].second < y)
                    wmax = max(wmax, minas[j].second);
                else if (minas[j].second > y)
                    wmin = min(wmin, minas[j].second);
                else
                    limite = true;
            }
        }

        return {A, B};
    }
};

int main() {
    while (true) {
        int x1, y1, x2, y2, N;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
            break;

        cin >> N;
        CampoMinado campo(x1, y1, x2, y2, N);

        for (int i = 0; i < N; ++i) {
            int x, y;
            cin >> x >> y;
            campo.adicionarMina(x, y);
        }

        pair<int, int> resultado = campo.encontrarMaiorRegiaoSegura();
        cout << resultado.first << " " << resultado.second << endl;
    }

    return 0;
}
