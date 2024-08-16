#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int N, K;
    while (cin >> N >> K) {
        vector<int> P(N);
        vector<int> C(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> P[i];
        }
        
        for (int i = 0; i < N; ++i) {
            cin >> C[i];
        }
        
        vector<vector<double>> dp(N + 1, vector<double>(K + 1, 0.0));

        for (int i = N - 1; i >= 0; --i) {
            for (int j = 0; j <= K; ++j) {
                // Caso Fernando erre a pergunta i, o prêmio esperado é 0.
                double expected_value_if_wrong = 0.0;
                
                // Caso Fernando acerte a pergunta i.
                double expected_value_if_right = P[i];
                if (i + 1 < N) {
                    expected_value_if_right += dp[i + 1][j];
                }
                
                double prob_right = C[i] / 100.0;
                double prob_wrong = 1.0 - prob_right;
                
                double expected_value = prob_right * expected_value_if_right + prob_wrong * expected_value_if_wrong;

                // Considerando a opção de pular a pergunta i se j > 0.
                if (j > 0) {
                    double expected_value_if_skip = P[i];
                    if (i + 1 < N) {
                        expected_value_if_skip += dp[i + 1][j - 1];
                    }
                    expected_value = max(expected_value, expected_value_if_skip);
                }
                
                dp[i][j] = expected_value;
            }
        }
        
        cout << fixed << setprecision(2) << dp[0][K] << endl;
    }

    return 0;
}
