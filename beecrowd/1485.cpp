#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int MAXN = 259;
const int INF = numeric_limits<int>::max();

int main() {
    int S, B;
    vector<int> x(MAXN), y(MAXN);
    vector<vector<int>> dp(MAXN, vector<int>(MAXN, -INF));

    while (cin >> S >> B && S != 0) {
        for (int i = 0; i < S; i++) {
            cin >> x[i];
        }
        
        for (int i = 0; i < B; i++) {
            cin >> y[i];
            y[i] = -y[i]; 
        }

        int maxRevenue = -INF;

        for (int i = 0; i < S; i++) {
            dp[0][i] = y[0] * (x[i] + x[(i + 1) % S]);

            for (int k = 1; k < S; k++) {
                int v = (i + k) % S;
                dp[0][v] = max(y[0] * (x[v] + x[(v + 1) % S]), dp[0][(v + S - 1) % S]);
            }

            for (int j = 1; j < B; j++) {
                fill(dp[j].begin(), dp[j].end(), -INF);
                
                for (int k = j * 2; k < S - 1; k++) {
                    int v = (i + k) % S;
                    dp[j][v] = max(y[j] * (x[v] + x[(v + 1) % S]) + dp[j - 1][(v + S - 2) % S], dp[j][(v + S - 1) % S]);
                }
            }

            maxRevenue = max(maxRevenue, dp[B - 1][(i + S - 2) % S]);
        }

        cout << maxRevenue << endl;
    }

    return 0;
}
