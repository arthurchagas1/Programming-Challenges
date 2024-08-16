#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <unordered_set>
#include <algorithm>

using namespace std;

const double PI = acos(-1);
using cd = complex<double>;

void fft(vector<cd> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;

        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; ++j) {
                cd u = a[i + j];
                cd v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd &x : a) {
            x /= n;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    // Calcular os pesos dos caracteres e as somas parciais
    vector<int> weights(n);
    vector<int> sums(n);
    int total_sum = 0;
    for (int i = 0; i < n; ++i) {
        weights[i] = s[i] - 'a' + 1;
        total_sum += weights[i];
        sums[i] = total_sum;
    }

    // Preparar os vetores para a FFT
    int size = 1;
    while (size <= 2 * total_sum) {
        size <<= 1;
    }
    vector<cd> P(size), Q(size);

    for (int i = 0; i < n; ++i) {
        P[sums[i]] += 1;
    }
    Q[total_sum] += 1;
    for (int i = 0; i < n - 1; ++i) {
        Q[total_sum - sums[i]] += 1;
    }

    // Aplicar FFT nos vetores
    fft(P, false);
    fft(Q, false);

    // Multiplicar os resultados da FFT ponto a ponto
    for (int i = 0; i < size; ++i) {
        P[i] *= Q[i];
    }

    // Aplicar a FFT inversa
    fft(P, true);

    // Contar os pesos distintos das subcadeias
    unordered_set<int> distinct_weights;
    for (int i = total_sum + 1; i <= 2 * total_sum; ++i) {
        if (round(P[i].real()) > 0) {
            distinct_weights.insert(i);
        }
    }

    // Imprimir o resultado
    cout << distinct_weights.size() << "\n";

    return 0;
}
