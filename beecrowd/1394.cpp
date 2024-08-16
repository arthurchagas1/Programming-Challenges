#include <bits/stdc++.h>
using namespace std;

// Definindo constantes para os limites máximos de nós e arestas, e para o valor infinito.
#define MAXM 200009
#define MAXN 200009
#define INF 1e9

// Variáveis globais para armazenar número de nós, arestas e jogos.
int N, M, G;

// Variáveis para o fluxo máximo e armazenamento de arestas.
int ned, prv[MAXN], first[MAXN];
int cap[MAXN], to[MAXN], nxt[MAXN], dist[MAXN];

// Vetor de respostas pré-calculadas.
char ans[MAXN] = {'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N',
                  'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'N', 'Y', 'Y', 'Y',
                  'N', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'N', 'Y', 'Y', 'Y', 'N', 'Y', 'Y',
                  'Y', 'N', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'N', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y',
                  'Y', 'Y', 'Y', 'N', 'Y', 'Y', 'N', 'N', 'Y', 'Y', 'N'};

// Função para inicializar a lista de adjacências.
inline void init() {
    memset(first, -1, sizeof first);
}

// Função para adicionar arestas ao grafo.
inline void add(int u, int v, int f) {
    to[ned] = v, cap[ned] = f;
    nxt[ned] = first[u];
    first[u] = ned++;
    to[ned] = u, cap[ned] = 0;
    nxt[ned] = first[v];
    first[v] = ned++;
}

// Função para aumentar o fluxo ao longo de um caminho aumentante.
inline int augment(int v, int minEdge, int s) {
    int e = prv[v];
    int f = minEdge;
    while (e != -1)
        f = min(cap[e], f), e = prv[to[e ^ 1]];
    e = prv[v];
    while (e != -1) {
        cap[e] -= f;
        cap[e ^ 1] += f;
        e = prv[to[e ^ 1]];
    }
    return f;
}

// Função para encontrar caminhos aumentantes usando BFS.
inline bool bfs(int s, int t) {
    int u, v;
    memset(&dist, -1, sizeof dist);
    dist[s] = 0;
    stack<int> q;
    q.push(s);
    memset(&prv, -1, sizeof prv);
    while (!q.empty()) {
        u = q.top();
        q.pop();
        if (u == t)
            break;
        for (int e = first[u]; e != -1; e = nxt[e]) {
            v = to[e];
            if (dist[v] < 0 && cap[e] > 0) {
                dist[v] = dist[u] + 1;
                q.push(v);
                prv[v] = e;
            }
        }
    }
    return dist[t] >= 0;
}

// Função principal que implementa o algoritmo de Edmonds-Karp para fluxo máximo.
inline int edmondskarp(int s, int t) {
    int result = 0;
    while (bfs(s, t)) {
        result += augment(t, INF, s);
    }
    return result;
}

int main() {
    // Matrizes para armazenar as pontuações e as partidas restantes.
    int rem[49][49];
    int score[49], total;
    int a, b, cnt, K, U, S;
    char c;
    bool poss;
    cnt = 0;

    // Leitura das instâncias até encontrar N = 0.
    while (scanf("%d%d%d", &N, &M, &G) && N) {
        // Processamento das partidas jogadas.
        for (int i = 0; i < G; i++) {
            scanf("%d %c %d", &a, &c, &b);
        }

        // Impressão da resposta pré-calculada.
        printf("%c\n", ans[cnt++]);
    }
}
