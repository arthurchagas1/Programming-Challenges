#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cstring>

using namespace std;

// Função para converter nome em sequência de números
vector<int> convertName(const string& name) {
    vector<int> seq;
    map<char, int> firstAppearance;
    for (char ch : name) {
        if (firstAppearance.find(ch) == firstAppearance.end()) {
            firstAppearance[ch] = ch - 'A' + 1;
        } else {
            firstAppearance[ch] += 26;
        }
        seq.push_back(firstAppearance[ch]);
    }
    return seq;
}

// Função para calcular a distância de edição mínima para tornar duas sequências iguais
int editDistance(const vector<int>& a, const vector<int>& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    int lcs = dp[n][m];
    return (n - lcs) + (m - lcs);
}

// Função para resolver o problema do casamento de bipartido máximo
bool bpm(int u, const vector<vector<int>>& bpGraph, vector<bool>& seen, vector<int>& matchR) {
    for (int v = 0; v < bpGraph[u].size(); v++) {
        if (bpGraph[u][v] && !seen[v]) {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(matchR[v], bpGraph, seen, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM(const vector<vector<int>>& bpGraph) {
    vector<int> matchR(bpGraph[0].size(), -1);
    int result = 0;
    for (int u = 0; u < bpGraph.size(); u++) {
        vector<bool> seen(bpGraph[0].size(), false);
        if (bpm(u, bpGraph, seen, matchR))
            result++;
    }
    return result;
}

int main() {
    int N, M;
    while (cin >> N >> M && (N || M)) {
        vector<string> friends(N), toys(M);

        for (int i = 0; i < N; ++i)
            cin >> friends[i];
        for (int i = 0; i < M; ++i)
            cin >> toys[i];

        vector<vector<int>> friendSeqs(N), toySeqs(M);
        for (int i = 0; i < N; ++i)
            friendSeqs[i] = convertName(friends[i]);
        for (int i = 0; i < M; ++i)
            toySeqs[i] = convertName(toys[i]);

        vector<vector<int>> bpGraph(N, vector<int>(M, 0));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (editDistance(friendSeqs[i], toySeqs[j]) % 5 == 0) {
                    bpGraph[i][j] = 1;
                }
            }
        }

        int maxMatches = maxBPM(bpGraph);
        double percentage = (100.0 * maxMatches) / N;
        cout<< "P = " << fixed << setprecision(2) << percentage << endl;
    }

    return 0;
}
