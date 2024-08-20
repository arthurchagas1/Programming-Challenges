#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Brinquedo {
public:
    unsigned short tempo;
    unsigned short qtsPontos;
    double razaoPontoTempo;

    Brinquedo(unsigned short t, unsigned short p) {
        tempo = t;
        qtsPontos = p;
        razaoPontoTempo = static_cast<double>(p) / t;
    }
};

bool compara(const Brinquedo &a, const Brinquedo &b) {
    return a.razaoPontoTempo > b.razaoPontoTempo;
}

int main() {
    unsigned short instancia = 0;

    while (true) {
        unsigned short qtsAtracoes, limiteTempo;
        cin >> qtsAtracoes >> limiteTempo;

        if (qtsAtracoes == 0)
            break;

        vector<Brinquedo> brinquedos;

        for (unsigned short i = 0; i < qtsAtracoes; ++i) {
            unsigned short tempo, qtsPontos;
            cin >> tempo >> qtsPontos;
            brinquedos.emplace_back(tempo, qtsPontos);
        }

        // Ordena os brinquedos pela razão pontos/tempo de forma decrescente
        sort(brinquedos.begin(), brinquedos.end(), compara);

        unsigned short pontoTotal = 0, tempoTotal = 0;
        unsigned short i = 0;

        while (i < qtsAtracoes) {
            unsigned short aux = tempoTotal + brinquedos[i].tempo;

            // Tenta adicionar o brinquedo se o tempo total não ultrapassar o limite
            if (aux <= limiteTempo) {
                pontoTotal += brinquedos[i].qtsPontos;
                tempoTotal = aux;
            } else {
                i++;
            }
        }

        cout << "Instancia " << ++instancia << endl;
        cout << pontoTotal << endl << endl;
    }

    return 0;
}
