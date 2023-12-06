#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <queue>

using namespace std;

template<typename T>
void print(vector<T> sez) {
    for (T x : sez) {
        if (x == 1) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
}

int BFS(int x, vector<vector<int>> &adj, vector<int> &vis, vector<int> &seq) {

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

            // Preverimo ce gre lahko sem

            for (int a : adj[y]) {

                if (vis[a] == kam_gre) {
                    return 1;
                }
            }

            vis[y] = kam_gre;
        }

        kam_gre *= -1;
    }

    return 0;
}

int main() {

    int n,m;
    cin >> n >> m;

    vector<vector<int>> sosedi(n);

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        sosedi[a-1].push_back(b-1);
        sosedi[b-1].push_back(a-1);
    }

    /* 
    for (int x = 0; x < n; x++) {
        cout << x << ": ";
        print(sosedi[x]);
    }*/

    int p;
    
    vector<int> vis(n);
    for (int i = 0; i < n; i++) { 
        if (vis[i] == 0) { 
            vector<int> seqB;
            p = BFS(i, sosedi, vis, seqB);

            if (p == 1) {
                break;
            } 
        }
    }
    if (p == 1) {
        cout << -1 << endl;
    } else {
        print(vis);
    }
}