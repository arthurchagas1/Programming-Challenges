#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MATRIX_SIZE = 100;

class Matrix {
public:
    int a[MATRIX_SIZE][MATRIX_SIZE];
    int n;

    Matrix(int size) : n(size) {
        memset(a, 0, sizeof(a));
    }
    
    void init() {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                a[i][j] = (i == j);
    }
    
    Matrix operator+(const Matrix &B) const {
        Matrix C(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                C.a[i][j] = (a[i][j] + B.a[i][j]);
        return C;
    }
    
    Matrix operator*(const Matrix &B) const {
        Matrix C(n);
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < n; ++k)
                for (int j = 0; j < n; ++j)
                    C.a[i][j] = (C.a[i][j] + a[i][k] * B.a[k][j]);
        return C;
    }
    
    Matrix operator^(const long long &t) const {
        Matrix A = (*this), res(n);
        res.init();
        long long p = t;
        while (p) {
            if (p & 1) res = res * A;
            A = A * A;
            p >>= 1;
        }
        return res;
    }
};

class PermutationCipher {
private:
    int n, m;
    int p[MATRIX_SIZE], num[MATRIX_SIZE];
    char s[MATRIX_SIZE];
    
    void readInput() {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &num[i]);
        
        for (int i = 1; i <= n; ++i)
            p[num[i]] = i;
        
        getchar();
        fgets(s, MATRIX_SIZE, stdin);
        s[strcspn(s, "\n")] = '\0';  // Remove newline character if exists
    }
    
    Matrix createInitialMatrix() {
        Matrix origin(n);
        memset(origin.a, 0, sizeof(origin.a));
        for (int i = 0; i < n; ++i)
            origin.a[i][p[i + 1] - 1] = 1;
        return origin;
    }

    Matrix createInitialSequenceMatrix() {
        Matrix A(n);
        memset(A.a, 0, sizeof(A.a));
        for (int i = 0; i < n; ++i)
            A.a[i][0] = i;
        return A;
    }

public:
    void run() {
        while (scanf("%d%d", &n, &m) != EOF) {
            if (n == 0 && m == 0)
                break;
            
            readInput();
            
            Matrix origin = createInitialMatrix();
            origin = origin ^ m;
            
            Matrix A = createInitialSequenceMatrix();
            Matrix ans = origin * A;
            
            for (int i = 0; i < n; ++i)
                printf("%c", s[ans.a[i][0]]);
            
            printf("\n");
        }
    }
};

int main() {
    PermutationCipher cipher;
    cipher.run();
    
    return 0;
}
