#include <iostream>
#include <cmath>

using namespace std;

// Função para calcular o máximo divisor comum usando o algoritmo de Euclides
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Função para calcular o inverso multiplicativo usando o algoritmo estendido de Euclides
long long modInverse(long long e, long long phi) {
    long long t = 0, newt = 1;
    long long r = phi, newr = e;
    
    while (newr != 0) {
        long long quotient = r / newr;
        long long temp;

        temp = t;
        t = newt;
        newt = temp - quotient * newt;

        temp = r;
        r = newr;
        newr = temp - quotient * newr;
    }
    
    if (r > 1) {
        throw "e is not invertible";
    }
    if (t < 0) {
        t = t + phi;
    }
    
    return t;
}

// Função para calcular a exponenciação modular
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Função principal para descriptografar a mensagem
long long decryptRSA(long long N, long long E, long long C) {
    // Fatorar N para encontrar P e Q
    long long P, Q;
    for (long long i = 2; i <= sqrt(N); i++) {
        if (N % i == 0) {
            P = i;
            Q = N / i;
            break;
        }
    }
    
    // Calcular φ(N)
    long long phi = (P - 1) * (Q - 1);
    
    // Encontrar D, o inverso multiplicativo de E módulo φ(N)
    long long D = modInverse(E, phi);
    
    // Descriptografar a mensagem
    long long M = modPow(C, D, N);
    
    return M;
}

int main() {
    long long N, E, C;
    cin >> N >> E >> C;
    
    try {
        long long M = decryptRSA(N, E, C);
        cout << M << endl;
    } catch (const char* msg) {
        cerr << msg << endl;
    }
    
    return 0;
}
