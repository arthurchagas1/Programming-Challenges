#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

typedef pair<int, int> PairInt;
const int INF = numeric_limits<int>::max();

vector<vector<PairInt>> graph;
vector<int> component;
vector<int> largest_cycle;
vector<int> no_cycle;
vector<int> cycle_size;
vector<int> entry_time;

int num_nodes, num_edges;
int time_counter, component_id, cycle_id;

int dfs(int node, int parent) {
    int cycle_start = -1;
    component[node] = component_id;
    entry_time[node] = time_counter++;
    
    for (auto &edge : graph[node]) {
        int weight = edge.first;
        int neighbor = edge.second;
        if (neighbor == parent) continue;
        
        if (entry_time[neighbor] < entry_time[node]) {
            no_cycle[node] = neighbor;
            cycle_start = neighbor;
        } else if (component[neighbor] == -1) {
            int result = dfs(neighbor, node);
            if (result != -1) {
                no_cycle[node] = result;
                if (result == node) {
                    cycle_start = -1;
                } else {
                    cycle_start = result;
                }
            }
        }
    }
    
    return cycle_start;
}

int dijkstra(int start, int min_cycle_size) {
    unordered_set<int> visited;
    unordered_map<int, int> distances;
    priority_queue<PairInt, vector<PairInt>, greater<PairInt>> pq;
    
    pq.push({distances[start] = 0, start});
    int min_distance = INF;
    
    while (!pq.empty()) {
        int current_node = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();
        
        if (no_cycle[current_node] != no_cycle[start] &&
            no_cycle[current_node] != -1 &&
            cycle_size[no_cycle[current_node]] >= min_cycle_size) {
            min_distance = min(min_distance, 2 * current_distance + cycle_size[no_cycle[current_node]]);
        }
        
        visited.insert(current_node);
        
        for (const auto &edge : graph[current_node]) {
            int weight = edge.first;
            int neighbor = edge.second;
            
            if (visited.count(neighbor)) continue;
            
            int new_distance = current_distance + weight;
            if (!distances.count(neighbor)) {
                distances[neighbor] = INF;
            }
            
            if (new_distance < distances[neighbor]) {
                pq.push({distances[neighbor] = new_distance, neighbor});
            }
        }
    }
    
    return min_distance;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while (cin >> num_nodes >> num_edges) {
        component_id = 0;
        time_counter = 0;
        cycle_id = 0;
        
        graph.assign(num_nodes, vector<PairInt>());
        component.assign(num_nodes, -1);
        no_cycle.assign(num_nodes, -1);
        entry_time.assign(num_nodes, INF);
        
        for (int i = 0; i < num_edges; i++) {
            int a, b, weight;
            cin >> a >> b >> weight;
            a--;
            b--;
            graph[a].push_back({weight, b});
            graph[b].push_back({weight, a});
        }
        
        for (int i = 0; i < num_nodes; i++) {
            if (component[i] == -1) {
                dfs(i, i);
                component_id++;
            }
        }
        
        cycle_size.assign(num_nodes, 0);
        
        for (int node = 0; node < num_nodes; node++) {
            if (no_cycle[node] == -1) continue;
            for (const auto &edge : graph[node]) {
                if (no_cycle[node] == no_cycle[edge.second]) {
                    cycle_size[no_cycle[node]] += edge.first;
                }
            }
        }
        
        for (int &size : cycle_size) {
            size /= 2;
        }
        
        int queries;
        cin >> queries;
        while (queries--) {
            int start_node, min_cycle_size;
            cin >> start_node >> min_cycle_size;
            start_node--;
            
            if (no_cycle[start_node] != -1 && cycle_size[no_cycle[start_node]] >= min_cycle_size) {
                cout << min(dijkstra(start_node, min_cycle_size), cycle_size[no_cycle[start_node]]) << "\n";
            } else {
                int result = dijkstra(start_node, min_cycle_size);
                if (result == INF) {
                    cout << "-1\n";
                } else {
                    cout << result << "\n";
                }
            }
        }
    }
    
    return 0;
}
