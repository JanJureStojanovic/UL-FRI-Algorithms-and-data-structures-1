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
            int d = dist[x]+  w;
            if (dist[y] == -1 || d < dist[y]) {
                dist[y] = d; 
                prev[y] = x;
                pq.push({d,y});
            }
        }
    }
}

// Method that returns a vector of consecutive nodes that create the shortest path
vector<int> shortest_path(vector<int> prev, int n) {

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
    for (int i=0;i<m;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        adjw[a].push_back({b,w});
        adjw[b].push_back({a,w});
    }

    vector<int> dist, prev;
    dijkstra_PQ(adjw,0,dist,prev);

    vector<int> shortest_path_edges = shortest_path(prev, n);

    print(shortest_path_edges);

    return 0;
  
}