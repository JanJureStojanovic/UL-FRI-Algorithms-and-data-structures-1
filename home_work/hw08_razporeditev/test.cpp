#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <queue>

using namespace std;

template<typename T>
void print(vector<T> sez) {
    for (T x : sez) cout << x << " ";
    cout << endl;
}

void BFS(int x, vector<vector<int>> &adj, vector<int> &vis, vector<int> &seq) {

    int kam_gre = 1;

    queue<int> q;
    q.push(x); 

    vis[x] = kam_gre;

    kam_gre *= -1;

    while (!q.empty()) {
        x=q.front();
        q.pop();
        seq.push_back(x);
        for (int y : adj[x]) if (vis[y]==0) {
            q.push(y); 
            vis[y] = kam_gre;
        }

        kam_gre *= -1;
    }
}

int main() {

    int n,m;
    cin >> n >> m;

    vector<vector<int>> sosedi(n);

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        sosedi[a].push_back(b);
        sosedi[b].push_back(a);
    }

    for (int x = 0; x < n; x++) {
        cout << x << ": ";
        print(sosedi[x]);
    }
    
    vector<int> vis(n);
    for (int i = 0; i < n; i++) { 
        if (vis[i] == 0) { 
            vector<int> seqB;
            BFS(i, sosedi, vis, seqB);
            print(seqB);    
        }
    }
}