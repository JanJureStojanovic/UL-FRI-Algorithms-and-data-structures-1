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

void dijkstra(vector<vector<pair<int, int>>> &adjw, int start, vector<int> &dist, vector<int> &prev) {
    int n = adjw.size();
    dist = vector<int>(n,-1); 
    prev = vector<int>(n,-1);
    vector<int> p(n,-1);  // provisional distance (-1=unvisited, -2=done)
    p[start] = 0;

    while (1) {

        int x = -1;  // smallest provisional

        for (int i = 0; i < n; i++) if (p[i] >= 0) {
            if (x == -1 || p[i] < p[x]) x=i;
        }

        if (x == -1) break;

        dist[x] = p[x];
        p[x] = -2;
        
        for (auto [y,w] : adjw[x]) {  // update neighbors
            int d = dist[x] + w;
            if (p[y] == -1 || (p[y] >= 0 && d < p[y])) { 
                p[y] = d; 
                prev[y]=x; 
            }
        }
    }
}


int main() {

    int n, m;
    cin >> n >> m;

    // Our weighted graph data structure
    cin >> n >> m;
    vector<VII> adjw(n);
    for (int i=0;i<m;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        adjw[a].push_back({b,w});
        adjw[b].push_back({a,w});
    }

    vector<int> dist, prev;
    dijkstra(adjw,0,dist,prev);
    print(dist); print(prev);
    
    return 0;
}