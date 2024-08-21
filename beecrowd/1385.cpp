#include <bits/stdc++.h>
using namespace std;

#define MAXN 10

class PriceSolver {
private:
    string lines[MAXN];
    string names[MAXN], prices[MAXN];
    int N, K, pos[MAXN], res[MAXN][MAXN];

    bool solve(int n, int k, int sum) {
        if (k == K) {
            int val = 0, acum = 0;
            for (int i = pos[n]; i < (int)prices[n].size(); i++) {
                val = val * 10 + prices[n][i] - '0';
            }
            for (int i = 0; i < K; i++) acum += res[n][i];
            if (acum != val) return false;
            res[n][k] = val;
            if (n == N + 1) return true;
            return solve(n + 1, k, sum);
        }

        int val = 0, u, rem = K - k, left;
        int m = min(pos[n] + 3, (int)prices[n].size());
        if (n == N + 1) m = (int)prices[n].size();
        u = pos[n];

        for (int i = pos[n]; i < m; i++) {
            val = val * 10 + prices[n][i] - '0';
            left = prices[n].size() - i - 1;

            pos[n] = i + 1;
            res[n][k] = val;
            if (n <= N && solve(n + 1, k, sum + val)) return true;
            else if (n == N + 1) {
                if (sum == val && solve(1, k + 1, 0)) return true;
                if (val > sum) {
                    pos[n] = u;
                    break;
                }
            }
            pos[n] = u;

            if (prices[n][u] == '0') break;
        }
        return false;
    }

public:
    void readInput() {
        int n = 0;
        while (cin >> lines[n]) {
            if (lines[n][0] == 'T' && lines[n][1] == 'P') break;
            if (n > 0) {
                string u = "";
                size_t i = 0;
                while (i < lines[n].size()) {
                    char c = lines[n][i];
                    if (isalpha(c)) u.push_back(c);
                    else {
                        names[n] = u;
                        break;
                    }
                    i++;
                }
                while (i < lines[n].size()) prices[n].push_back(lines[n][i++]);
            }
            n++;
            prices[n] = "";
            pos[n] = 0;
        }
        for (size_t i = 2; i < lines[n].size(); i++) prices[n].push_back(lines[n][i]);
        N = n - 1;
        K = (lines[0].size() - 6) / 2;
    }

    void solveProblem() {
        memset(pos, 0, sizeof(pos));
        memset(res, 0, sizeof(res));

        solve(1, 0, 0);
    }

    void printResults() {
        for (int k = 0; k < K; k++) printf("P%d ", k + 1);
        printf("Totals\n");
        for (int i = 1; i <= N; i++) {
            printf("%s", names[i].c_str());
            for (int k = 0; k <= K; k++) {
                printf(" %d", res[i][k]);
            }
            printf("\n");
        }
        printf("TP");
        for (int k = 0; k <= K; k++) {
            printf(" %d", res[N+1][k]);
        }
        printf("\n");
    }
};

int main() {
    int t;
    cin >> t;

    while (t-- > 0) {
        PriceSolver solver;
        solver.readInput();
        solver.solveProblem();
        solver.printResults();
    }

    return 0;
}
