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

class DisjointSet {  // Union-Find
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent = vector<int>(n);
        size = vector<int>(n);
        for (int i=0;i<n;i++) {  // individual sets
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int root(int x) {  // find
        if (parent[x]==x) return x;  // reached the root        
        int r = root(parent[x]);
        parent[x] = r;  // path compression
        return r;
    }

    void join(int x, int y) {  // union by size
        x=root(x); y=root(y);  // replace by roots
        if (x==y) return;
        if (size[x]>size[y]) swap(x,y);  // make x smaller
        parent[x] = y;  // attach to larger root
        size[y] += size[x];
    }    
};


int main() {

    int v, s;
    cin >> v >> s;

    int t;
    int max = 0;

    vector<vector<int>> islands(v);

    vector<VII> matrix(100000);

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < s; j++) {
            cin >> t;
            islands[i].push_back(t);
            matrix[t].push_back({i,j});
            if (t > max) {
                max = t;
            }
        }
    }

    /* 
    cout << "\n";
    cout << "Max: " << max << "\n";
    cout << "\n";

    for (int i = 0; i <= max; i++) {
        cout << i << ": ";
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << "(" << matrix[i][j].first << ", " << matrix[i][j].second << ") ";
        }
        cout << "\n";
    }

    cout << "\n";


    for (int i = 0; i < max; i++) {

        for (int j = 0; j < v; j++) {
            for (int k = 0; k < s; k++) {

                if (islands[j][k] - i > 0) { 
                    cout << islands[j][k] - i << " ";
                } else {
                    cout << 0 << " ";
                }
            }
            cout << "\n";
        }
        cout << "\n";

    }
    */

    return 0;
}