#include <iostream>
#include <vector>

using namespace std;

int main() {
    int V, M;
    cin >> V >> M;

    vector<int> moedas(M);
    for (int i = 0; i < M; ++i) {
        cin >> moedas[i];
    }

    vector<bool> dp(V + 1, false);
    dp[0] = true;

    for (int i = 0; i < M; ++i) {
        for (int j = V; j >= moedas[i]; --j) {
            if (dp[j - moedas[i]]) {
                dp[j] = true;
            }
        }
    }

    if (dp[V]) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}
