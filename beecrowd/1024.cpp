#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Função para deslocar as letras em 3 posições na tabela ASCII
string deslocarLetras(string texto) {
    for (char& c : texto) {
        if (isalpha(c)) {
            c += 3;
        }
    }
    return texto;
}

// Função para inverter a string
string inverterString(string texto) {
    reverse(texto.begin(), texto.end());
    return texto;
}

// Função para deslocar os caracteres a partir da metade para a esquerda
string deslocarMetade(string texto) {
    int metade = texto.size() / 2;
    for (int i = metade; i < texto.size(); ++i) {
        texto[i] -= 1;
    }
    return texto;
}

// Função principal que processa a criptografia de uma linha
string criptografar(string linha) {
    linha = deslocarLetras(linha);   // Primeira passada
    linha = inverterString(linha);   // Segunda passada
    linha = deslocarMetade(linha);   // Terceira passada
    return linha;
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Ignora o caractere de nova linha após o número

    for (int i = 0; i < N; ++i) {
        string linha;
        getline(cin, linha);
        cout << criptografar(linha) << endl;
    }

    return 0;
}
