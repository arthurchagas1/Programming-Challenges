#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>

using namespace std;

const int MAXN = 205;  // Suficiente para incluir todos cavalos, policiais, fonte e sumidouro

int capacidade[MAXN][MAXN];
int fluxo[MAXN][MAXN];
vector<int> adj[MAXN];
int pai[MAXN];
int visitado[MAXN];

bool bfs(int s, int t) {
    memset(visitado, 0, sizeof(visitado));
    queue<int> q;
    q.push(s);
    visitado[s] = 1;
    pai[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visitado[v] && capacidade[u][v] - fluxo[u][v] > 0) {
                q.push(v);
                pai[v] = u;
                visitado[v] = 1;
                if (v == t)
                    return true;
            }
        }
    }
    return false;
}

int edmondsKarp(int s, int t) {
    int maxFlow = 0;
    memset(fluxo, 0, sizeof(fluxo));

    while (bfs(s, t)) {
        int pathFlow = numeric_limits<int>::max();
        for (int v = t; v != s; v = pai[v]) {
            int u = pai[v];
            pathFlow = min(pathFlow, capacidade[u][v] - fluxo[u][v]);
        }

        for (int v = t; v != s; v = pai[v]) {
            int u = pai[v];
            fluxo[u][v] += pathFlow;
            fluxo[v][u] -= pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int n, m, k;
    int instancia = 1;

    while (cin >> n >> m >> k) {
        int s = 0; // Fonte
        int t = n + m + 1; // Sumidouro

        // Limpar dados antigos
        for (int i = 0; i <= n + m + 1; i++) {
            adj[i].clear();
            for (int j = 0; j <= n + m + 1; j++)
                capacidade[i][j] = 0;
        }

        // Capacidades dos cavalos
        for (int i = 1; i <= n; i++) {
            int c;
            cin >> c;
            capacidade[s][i] = c;
            adj[s].push_back(i);
            adj[i].push_back(s);
        }

        // Afinidades entre cavalos e policiais
        for (int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;
            int horse = u;
            int police = n + v;
            capacidade[horse][police] = 1;
            adj[horse].push_back(police);
            adj[police].push_back(horse);
        }

        // Conectar policiais ao sumidouro
        for (int i = 1; i <= m; i++) {
            int police = n + i;
            capacidade[police][t] = 1;
            adj[police].push_back(t);
            adj[t].push_back(police);
        }

        int maxPoliciais = edmondsKarp(s, t);

        cout << "Instancia " << instancia++ << endl;
        cout << maxPoliciais << endl << endl;
    }

    return 0;
}
