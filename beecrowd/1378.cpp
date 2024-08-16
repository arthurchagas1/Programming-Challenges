#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef pair<int, int> Point;

// Função para calcular a distância ao quadrado entre dois pontos
long long distanceSquared(const Point& a, const Point& b) {
    long long dx = a.first - b.first;
    long long dy = a.second - b.second;
    return dx * dx + dy * dy;
}

// Função para contar o número de triângulos isósceles
int countIsoscelesTriangles(const vector<Point>& points) {
    int N = points.size();
    int totalIsosceles = 0;

    // Itera sobre cada ponto como ponto de referência
    for (int i = 0; i < N; ++i) {
        vector<long long> distances;
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                distances.push_back(distanceSquared(points[i], points[j]));
            }
        }

        // Ordena as distâncias ao quadrado
        sort(distances.begin(), distances.end());

        // Conta os triângulos isósceles a partir do ponto de referência atual
        int count = 1;
        for (size_t j = 1; j < distances.size(); ++j) {
            if (distances[j] == distances[j - 1]) {
                ++count;
            } else {
                totalIsosceles += count * (count - 1) / 2;
                count = 1;
            }
        }
        totalIsosceles += count * (count - 1) / 2;
    }

    return totalIsosceles;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<Point> points(N);
        for (int i = 0; i < N; ++i) {
            cin >> points[i].first >> points[i].second;
        }
        cout << countIsoscelesTriangles(points) << endl;
    }
    return 0;
}
