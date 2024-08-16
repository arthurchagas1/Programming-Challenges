#include <iostream>
#include <cstdlib>

int main() {
    int n, *a, d, i, j, k = 2, maior = 1;
    std::cin >> n;
    a = reinterpret_cast<int*>(malloc(sizeof(int) * n));
    for(i = 0; i < n; i++) std::cin >> a[i];

    for(i = 1; i < n - 1; i++, k++) {
        if(a[i] < k) k = a[i];
        d = k + 1;
        while(--d > maior) {
            j = i;
            while(++j < n && --d > 1) {
                if(a[j] < d) break;
            }
            if(d == 1) maior = k;
        }
    }
    std::cout << maior << std::endl;
    free(a); // Não se esqueça de liberar a memória alocada
    return 0;
}

