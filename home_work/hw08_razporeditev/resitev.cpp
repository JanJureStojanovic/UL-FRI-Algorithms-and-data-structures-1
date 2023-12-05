#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef vector<pair<int,int>> VII;

template<typename T>
void print(vector<T> sez) {
    for (T x : sez) cout << x << " ";
    cout << endl;
}

void BFS(int n, vector<vector<int>> &sosedi, vector<int> &seq) {
    vector<int> vis(n);
    queue<int> q;
    q.push(0); vis[0]=1;
    while (!q.empty()) {
        int x=q.front(); q.pop();
        seq.push_back(x);
        for (int y : sosedi[x]) {
            if (!vis[y]) {
                q.push(y); vis[y]=1;
            }
        }
    }
}

void DFS(int x, vector<vector<int>> &sosedi, vector<int> &seq, vector<int> &vis) {
    seq.push_back(x);
    vis[x]=1;
    for (int y : sosedi[x]) if (!vis[y]) {
        DFS(y,sosedi,seq,vis);
    }
}

int main() {

    int n, m;
    fin >> n >> m;

    vector<vector<int>> sosedi(n);
    cout << "1";
    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        sosedi[a].push_back(b);
        sosedi[b].push_back(a);
    }
    cout << "2";
    for (int x = 0; x < n; x++) {
        cout << x << ": ";
        print(sosedi[x]);
    }
    cout << "3";
    vector<int> seqB;
    BFS(n,sosedi,seqB);
    print(seqB);

    vector<int> seqD, visD(n);
    DFS(0,sosedi,seqD,visD);
    print(seqD);

    return 0;
}