#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<pair<int,int>> VII;
typedef vector<vector<int>> VVI;

template<typename T>
void print(const vector<T> &sez) {
    for (T x : sez) cout << x << " ";
    cout << endl;
}


// Dijkstra shortest path algoritm
void dijkstra_PQ(vector<VII> &adjw, int start, vector<int> &dist, vector<int> &prev) {

    int n = adjw.size();
    dist = vector<int> (n,-1); 
    prev = vector<int> (n,-1);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    dist[start] = 0; 
    pq.push({0,start});

    while (!pq.empty()) {
        auto [d,x] = pq.top(); 
        pq.pop();
        if (dist[x] != d) continue;
        for (auto [y,w] : adjw[x]) {
            int d = dist[x] +  w;
            if (dist[y] == -1 || d < dist[y]) {
                dist[y] = d; 
                prev[y] = x;
                pq.push({d,y});
            }
        }
    }
}

// Method that returns a vector of consecutive nodes that create the shortest path
vector<int> shortest_path(vector<int> &prev, int n) {

    vector<int> shortest_path_vector;
    int i = n-1;

    while(i > 0) {
        shortest_path_vector.push_back(i);
        i = prev[i];
    }

    shortest_path_vector.push_back(i);
    return shortest_path_vector;
}

int main() {

    int n, m;
    cin >> n >> m;

    // Our weighted graph data structure
    vector<VII> adjw(n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adjw[a].push_back({b,w});
        adjw[b].push_back({a,w});
    }

    // Running the dijkstra algo for the 1st time and finding the shortest parh
    vector<int> dist, prev;
    dijkstra_PQ(adjw, 0, dist, prev);

    int shortest_path_all_nodes;
    int shortest_path_removed_node;

    if (dist[n-1] == -1) {
        // If a path doesn't exist we can stop the program
        cout << -1 << "\n";
        return 0;

    } else {

        // Set values;
        shortest_path_all_nodes = dist[n-1];
        shortest_path_removed_node = -1;

        // Shortest path nodes
        vector<int> shortest_path_edges = shortest_path(prev, n);

        // Remove each edge in shortest path and run the dijkstra_pq method
        for (int i = 0; i < shortest_path_edges.size() - 1; i++) {

            // Izberemo dve zaporedni vozlisci -> tvorita eno povezavo
            int x = shortest_path_edges[i];
            int y = shortest_path_edges[i + 1];
            int edge_weight;

            // Removing ad edge (1st)
            for (int j = 0; j < adjw[y].size(); j++) {
                if (adjw[y][j].first == x) {
                    edge_weight = adjw[y][j].second;
                    adjw[y].erase(adjw[y].begin() + j);
                }
            }

            // Removing an edge (2nd)
            for (int j = 0; j < adjw[x].size(); j++) {
                if (adjw[x][j].first == y) {
                    adjw[x].erase(adjw[x].begin() + j);
                }
            }

            // Running the dijkstra_pq algorithm and finding the new shortest path without the edge
            vector<int> dist, prev;
            dijkstra_PQ(adjw, 0, dist, prev);

            if ((dist[n - 1] != -1 && dist[n - 1] < shortest_path_removed_node) || 
                (dist[n - 1] != -1 && shortest_path_removed_node == -1)) {
                shortest_path_removed_node = dist[n - 1];
            }

            if (shortest_path_removed_node == shortest_path_all_nodes + 1) {
                break;
            }

            // Add back the edge
            adjw[x].push_back({y,edge_weight});
            adjw[y].push_back({x,edge_weight});
        }
    }

    cout << shortest_path_removed_node << endl;
  
}