#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>

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
    vector<int> parent, size, isin;
    DisjointSet(int n) {
        parent = vector<int>(n);
        size = vector<int>(n);
        isin = vector<int>(n);
        for (int i=0;i<n;i++) {  // individual sets
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int root(int x) {  // find
        if (parent[x]==x) return x;  // reached the root        
        int r = root(parent[x]); // recursive call
        parent[x] = r;  // path compression
        return r;
    }

    void add(int x) {
        isin[x] = 1;
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
    int max_height = 0;

    vector<VII> matrix(100000);

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < s; j++) {
            cin >> t;
            matrix[t].push_back({i,j});
            if (t > max_height) {
                max_height = t;
            }
        }
    }
/* 
    cout << "\n";

    // Output sprejetih infomacij po nivojih
    for (int i = 0; i <= max_height; i++) {
        cout << i << ": ";
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << "(" << matrix[i][j].first << ", " << matrix[i][j].second << ") ";
        }
        cout << "\n";
    }
    cout << "\n";
*/
    vector<int> islands;

    islands.push_back(0);

    int num_islands = 0;

    DisjointSet ds(v*s);

    int ds_num;

    for (int i = max_height; i > 0; i--) {

        for (int j = 0; j < matrix[i].size(); j++) {

            // Dodelimo specificno stevilko
            ds_num = matrix[i][j].first*s + matrix[i][j].second;

            // + 1
            if (ds.isin[ds_num + 1] == 1 && (ds_num + 1 < v*s) && ((ds_num + 1)/s == ds_num/s) && (ds.root(ds_num) != ds.root(ds_num + 1))) {
                ds.join(ds_num, ds_num + 1);
                num_islands--;
            }

            // - 1
            if (ds.isin[ds_num - 1] == 1 && (ds_num - 1 >= 0) && ((ds_num - 1)/s == ds_num/s) && (ds.root(ds_num) != ds.root(ds_num - 1))) {
                ds.join(ds_num, ds_num - 1);
                num_islands--;
            }

            // + s 
            if (ds.isin[ds_num + s] == 1 && (ds_num + s < v*s) && (ds.root(ds_num) != ds.root(ds_num + s))) {
                ds.join(ds_num, ds_num + s);
                num_islands--;
            }

            // -s 
            if (ds.isin[ds_num - s] == 1 && (ds_num - s >= 0) && (ds.root(ds_num) != ds.root(ds_num - s))) {
                ds.join(ds_num, ds_num - s);
                num_islands--;
            }  

            ds.add(ds_num);
            num_islands++;
        }

        islands.push_back(num_islands);

/* 
        cout << "----------------------" << endl;

        cout << "Number of islands: ";

        if (num_islands < 1) {
            cout << 1 << "\n";
        } else {
            cout << num_islands << "\n";
        }

        for (int k = 0; k < v*s; k++) {
            if (k % s == 0 && k != 0) {
                cout << "\n";
            }
            cout << ds.isin[k];
        }
        cout << "\n";
*/
    }
    
    //cout << "----------------------" << endl; 

    for (int i = islands.size() - 1; i >= 0; i--) {
        cout << islands[i] << "\n"; 
    }
}
