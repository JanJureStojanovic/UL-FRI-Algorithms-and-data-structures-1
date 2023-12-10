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

    /*
    for (int i = pot.size() - 1; i >= 0; i--) {
        cout << "(" << pot[i].first << ", " << pot[i].second << ")";
    }
    cout << endl;
    */
}

void Dijkstra(vector<VII> &adjw, int start, vector<int> &dist, vector<int> &prev) {

    int n = adjw.size(); // Stevilo vozlisc
    dist = vector<int>(n, -1); 
    prev = vector<int>(n, -1);
    vector<int> p(n, -1);  // Provisional distance (-1 = unvisited, -2 = done)
    
    p[start] = 0; // Od kjer smo zaceli je distanca 0

    while (1) {

        int x = -1;  // Smallest provisional
        for (int i = 0; i < n; i++) { 
            if (p[i] >= 0) {
                if (x == -1 || p[i] < p[x]) {
                    x = i;  
                } 
            }
        }

        if (x == -1) break;
        dist[x] = p[x]; 
        p[x] = -2;

        for (auto [y,w] : adjw[x]) {  // Update neighbors
            int d = dist[x] + w;
            if (p[y] == -1 || (p[y] >= 0 && d < p[y])) { 
                p[y] = d; 
                prev[y] = x; 
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
    Dijkstra(adjw,0,dist,prev);
    print(dist); 
    print(prev);

    vector<pair<int, int>> pot = path_finder(prev, n);

    return 0;
}