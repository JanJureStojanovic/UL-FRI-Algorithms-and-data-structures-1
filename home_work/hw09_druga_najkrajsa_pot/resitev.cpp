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

void removeEdge(vector<vector<pair<int, int>>>& graph, int u, int v) {
    // Iterate over each vertex and remove the edge (u, v) and (v, u)
    for (auto& neighbors : graph) {
        neighbors.erase(remove_if(neighbors.begin(), neighbors.end(),
                                  [u, v](const pair<int, int>& edge) {
                                      return (edge.first == u && edge.second == v) ||
                                             (edge.first == v && edge.second == u);
                                  }),
                        neighbors.end());
    }
}


vector<VII> remove_edge(vector<VII> adjw, pair<int, int> edge) {

    int x = edge.first;
    int y = edge.second;

    for(int i = 0; i < adjw[x].size(); i++) {
        if (adjw[x][i].first == y) {
            adjw[x].erase(adjw[x].begin() + i);
            break;
        }
    }

    for(int i = 0; i < adjw[y].size(); i++) {
        if (adjw[y][i].first == x) {
            adjw[y].erase(adjw[y].begin() + i);
            break;
        }
    }

    return adjw;
}

// Method that returns the edges that complete the shortest path 
vector<pair<int, int>> path_finder(vector<int> prev, int n) {

    // Vektor, ki hrani povezave, ki tvorijo naso pot
    vector<pair<int, int>> pot;
    int a = n - 1;

    while (a != 0) {
        pot.push_back(make_pair(prev[a], a));
        a = prev[a];
    }

    return pot;
}

void Dijkstra_PQ(vector<VII> &adjw, int start, vector<int> &dist, vector<int> &prev) {

    int n = adjw.size();
    dist = vector<int> (n,-1); 
    prev = vector<int> (n,-1);
    priority_queue<PII, vector<PII>, greater<PII>> pq;  // (distance, node)
    dist[start] = 0; 
    pq.push({0,start});

    while (!pq.empty()) {
        auto [d,x] = pq.top(); 
        pq.pop();
        if (dist[x] != d) continue;  // ignore old values
        for (auto [y,w] : adjw[x]) {  // update neighbors
            int d = dist[x]+  w;
            if (dist[y]==-1 || d<dist[y]) {
                dist[y]=d; prev[y]=x;
                pq.push({d,y});
            }
        }
    }
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
    Dijkstra_PQ(adjw,0,dist,prev);
    //print(dist); 
    //print(prev);

    vector<pair<int, int>> pot = path_finder(prev, n);

    int min_pot = 20000000;

    for (int i = 0; i < pot.size(); i++) {

        int attempt = 0;

        vector<VII> altered_adjw = adjw;
        removeEdge(altered_adjw, pot[i].first, pot[i].second);

        vector<int> dist1, prev1;

        Dijkstra_PQ(altered_adjw,0,dist1,prev1);


        attempt = dist[n-1];

        if (attempt < min_pot) {
            min_pot = attempt;
        }
    }

    cout << min_pot << "\n";

    return 0;
}