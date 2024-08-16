#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    // Declaração das variáveis para os pontos
    double x1, y1, x2, y2;
    
    // Leitura dos pontos
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    
    // Cálculo da distância usando a fórmula da distância euclidiana
    double distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    
    // Impressão do resultado com 4 casas decimais
    cout << fixed << setprecision(4) << distancia << endl;
    
    return 0;
}
