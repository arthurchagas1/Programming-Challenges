#include <iostream>
#include <cstdio>

using namespace std;

typedef long long int64;

class Matrix {
public:
    int64 mat[2][2];

    Matrix() {
        mat[0][0] = mat[0][1] = mat[1][0] = 1;
        mat[1][1] = 0;
    }

    Matrix operator*(const Matrix &other) const {
        Matrix result;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result.mat[i][j] = 0;
                for (int k = 0; k < 2; ++k) {
                    result.mat[i][j] += (this->mat[i][k] * other.mat[k][j]) % modValue;
                    result.mat[i][j] %= modValue;
                }
            }
        }
        return result;
    }

    static int64 modValue;
};

int64 Matrix::modValue = 0;

Matrix matrixExponentiation(Matrix base, int64 exponent, int64 mod) {
    Matrix::modValue = mod;
    Matrix result;
    result.mat[0][0] = result.mat[1][1] = 1;
    result.mat[0][1] = result.mat[1][0] = 0;

    while (exponent) {
        if (exponent & 1) {
            result = result * base;
        }
        base = base * base;
        exponent >>= 1;
    }

    return result;
}

int main() {
    int testCase = 1;
    int64 n, b;

    while (scanf("%lld %lld", &n, &b) && (n + b)) {
        Matrix fibMatrix;

        if (n <= 1) {
            printf("Case %d: %lld %lld 1\n", testCase++, n, b);
        } else {
            int64 result = (2 * matrixExponentiation(fibMatrix, n, b).mat[0][0] - 1) % b;
            if (result < 0) {
                result += b; // Ajuste para garantir que o resultado seja positivo
            }
            printf("Case %d: %lld %lld %lld\n", testCase++, n, b, result);
        }
    }

    return 0;
}
