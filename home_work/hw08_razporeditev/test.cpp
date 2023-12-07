#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <queue>

using namespace std;

// Profs. print template for vectors
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

// BFS algo metoda (odstranimo seq vector, ker seq ni pomemben)
int BFS(int x, vector<vector<int>> &adj, vector<int> &vis) {

    // New queue
    queue<int> q;
    q.push(x); 

    // Vsakic damo na 1 (leksikografsko uredimo 1 -> 2)
    vis[x] = 1;

    while (!q.empty()) {
        // Queue ops.
        x = q.front(); 
        q.pop();

        for (int y : adj[x]) {
            // Sosednje vozlisce ima isto vrednost oz. barvo -> napaka!
            if (vis[y] == vis[x]) {
                return 1;
            }
        }

        for (int y : adj[x]) {
            // Neobiskanim vozliscam dodelimo vrednost
            if (vis[y]==0) {
                q.push(y); 
                vis[y] = (vis[x] == 1 ) ? 2 : 1;
            }
        }
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

    int result;
    
    vector<int> vis;

    for (int i = 0; i < n; i++) { 

        // Najdemo vozlisce, ki se ni bilo obiskano
        if (vis[i] == 0) { 

            p = BFS(i, sosedi, vis);
            
            // Nasli smo error
            if (p == 1) {
                break;
            } 
        }
    }

    if (p == 1) {
        cout << -1 << "\n";
    } else { 
        print(vis);
    }
}