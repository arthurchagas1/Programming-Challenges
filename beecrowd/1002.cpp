#include <iostream>
#include <iomanip> // Biblioteca necessária para std::setprecision

int main() {
    const double PI = 3.14159; // Definição de π
    double raio; // Variável para armazenar o valor do raio

    // Leitura do valor do raio
    std::cin >> raio;

    // Cálculo da área
    double area = PI * raio * raio;

    // Configuração para imprimir o resultado com 4 casas decimais
    std::cout << "A=" << std::fixed << std::setprecision(4) << area << std::endl;

    return 0;
}
