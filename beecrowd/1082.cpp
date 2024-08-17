#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<char>& component) {
    visited[v] = true;
    component.push_back(v + 'a');  // Convertendo índice para letra
    
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, adj, visited, component);
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);  // Lista de adjacências
        vector<bool> visited(V, false);
        
        for (int i = 0; i < E; ++i) {
            char u, v;
            cin >> u >> v;
            adj[u - 'a'].push_back(v - 'a');
            adj[v - 'a'].push_back(u - 'a');
        }

        cout << "Case #" << t << ":\n";
        
        vector<vector<char>> components;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                vector<char> component;
                dfs(i, adj, visited, component);
                sort(component.begin(), component.end());
                components.push_back(component);
            }
        }

        for (const auto& component : components) {
            for (char node : component) {
                cout << node << ',';
            }
            cout << '\n';
        }

        cout << components.size() << " connected components\n\n";
    }

    return 0;
}
