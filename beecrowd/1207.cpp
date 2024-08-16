#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <numeric> // Adicionado para a função accumulate

using namespace std;

// Estrutura para representar uma aresta no grafo
struct Edge {
    int to, rev;
    int cap;
};

// Função para adicionar uma aresta ao grafo
void addEdge(vector<vector<Edge>> &graph, int from, int to, int cap) {
    Edge a = {to, (int)graph[to].size(), cap};
    Edge b = {from, (int)graph[from].size(), 0};
    graph[from].push_back(a);
    graph[to].push_back(b);
}

// BFS para encontrar um caminho de aumento no grafo residual
bool bfs(vector<vector<Edge>> &graph, int source, int sink, vector<int> &level) {
    fill(level.begin(), level.end(), -1);
    level[source] = 0;
    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &e : graph[u]) {
            if (level[e.to] == -1 && e.cap > 0) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }
    return level[sink] != -1;
}

// DFS para enviar fluxo ao longo do caminho de aumento encontrado pelo BFS
int dfs(vector<vector<Edge>> &graph, vector<int> &level, vector<int> &ptr, int u, int sink, int flow) {
    if (u == sink) return flow;

    for (; ptr[u] < graph[u].size(); ++ptr[u]) {
        Edge &e = graph[u][ptr[u]];

        if (level[e.to] == level[u] + 1 && e.cap > 0) {
            int df = dfs(graph, level, ptr, e.to, sink, min(flow, e.cap));
            if (df > 0) {
                e.cap -= df;
                graph[e.to][e.rev].cap += df;
                return df;
            }
        }
    }
    return 0;
}

// Função principal para calcular o fluxo máximo usando o algoritmo de Dinic
int maxFlow(vector<vector<Edge>> &graph, int source, int sink) {
    int flow = 0;
    vector<int> level(graph.size()), ptr(graph.size());

    while (bfs(graph, source, sink, level)) {
        fill(ptr.begin(), ptr.end(), 0);
        while (int pushed = dfs(graph, level, ptr, source, sink, INT_MAX)) {
            flow += pushed;
        }
    }
    return flow;
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<int> C(N);
        for (int i = 0; i < N; ++i) {
            cin >> C[i];
        }

        vector<int> P(M);
        for (int i = 0; i < M; ++i) {
            cin >> P[i];
        }

        vector<int> B(M);
        vector<vector<int>> categories(M);
        for (int i = 0; i < M; ++i) {
            cin >> B[i];
            categories[i].resize(P[i]);
            for (int j = 0; j < P[i]; ++j) {
                cin >> categories[i][j];
                categories[i][j]--; // Ajuste para índice 0-based
            }
        }

        int source = 0;
        int sink = N + M + 1;
        vector<vector<Edge>> graph(N + M + 2);

        for (int i = 0; i < M; ++i) {
            addEdge(graph, source, i + 1, B[i]);
        }

        for (int i = 0; i < N; ++i) {
            addEdge(graph, M + i + 1, sink, C[i]);
        }

        for (int i = 0; i < M; ++i) {
            for (int j : categories[i]) {
                addEdge(graph, i + 1, M + j + 1, INT_MAX);
            }
        }

        int max_benefit = accumulate(B.begin(), B.end(), 0);
        int min_cut = maxFlow(graph, source, sink);

        int result = max_benefit - min_cut;
        cout << result << endl;
    }

    return 0;
}
