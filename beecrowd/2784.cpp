#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    int weight;
};

// Estrutura para representar um vértice no grafo
struct Vertex {
    vector<Edge> edges;
};

// Função para calcular os menores caminhos (pings mínimos) usando o algoritmo de Dijkstra
vector<int> dijkstra(const vector<Vertex>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (const Edge& e : graph[u].edges) {
            int v = e.to;
            int w = e.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Vertex> graph(N + 1);

    // Lendo a configuração da rede
    for (int i = 0; i < M; ++i) {
        int Ui, Vi, Pi;
        cin >> Ui >> Vi >> Pi;
        graph[Ui].edges.push_back({Vi, Pi});
        graph[Vi].edges.push_back({Ui, Pi});
    }

    int S; // ilha onde o servidor será instalado
    cin >> S;

    // Calculando os menores caminhos de todas as ilhas até o servidor
    vector<int> distances = dijkstra(graph, S);

    int max_ping = INT_MIN;
    int min_ping = INT_MAX;

    // Encontrando o ping máximo e mínimo, excluindo a ilha onde o servidor está instalado
    for (int i = 1; i <= N; ++i) {
        if (i == S)
            continue;
        max_ping = max(max_ping, distances[i]);
        min_ping = min(min_ping, distances[i]);
    }

    // Calculando a diferença entre o ping da ilha com maior ping até o servidor e o ping da ilha com menor ping até o servidor
    int difference = max_ping - min_ping;

    cout << difference << endl;

    return 0;
}
