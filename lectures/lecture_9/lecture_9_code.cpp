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

vector<int> toposort(vector<vector<int>> &sosedi) {
    int n=sosedi.size();
    vector<int> indeg(n);
    for (int x=0;x<n;x++) {
        for (int y : sosedi[x]) indeg[y]++;
    }
    queue<int> q;
    for (int x=0;x<n;x++) if (indeg[x]==0) {
        q.push(x);
    }
    vector<int> seq;
    while (!q.empty()) {
        int x=q.front(); q.pop();
        seq.push_back(x);
        for (int y : sosedi[x]) {
            indeg[y]--;
            if (indeg[y]==0) q.push(y);
        }
    }
    return seq;
}

void Dijsktra(vector<vector<PII>> &sosedi, int start, vector<int> &dist, vector<int> &prev) {
    int n=sosedi.size();
    dist=vector<int>(n,-1); prev=vector<int>(n,-1);
    vector<int> p(n,-1);  // -1=neobiskano, -2=koncano
    p[start] = 0;
    while (1) {
        // najmanjsi v okolici
        int x=-1;
        for (int i=0;i<n;i++) if (p[i]>=0) {
            if (x==-1 || p[i]<p[x]) x=i;
        }
        if (x==-1) break;
        dist[x]=p[x]; p[x]=-2;
        // popravim potencialne razdalje
        for (auto [y,w] : sosedi[x]) {
            int d=dist[x]+w;
            if (p[y]==-1 || (p[y]>=0 && d<p[y])) {
                p[y]=d; prev[y]=x;
            }
        }
    }
}

void DijsktraPQ(vector<vector<PII>> &sosedi, int start, vector<int> &dist, vector<int> &prev) {
    int n=sosedi.size();
    dist=vector<int>(n,-1); prev=vector<int>(n,-1);
    priority_queue<PII, vector<PII>, greater<PII>> pq;  // min heap (dist, x)
    dist[start]=0; pq.push({0,start});
    while (!pq.empty()) {
        // najmanjsi v okolici
        auto [d,x]=pq.top(); pq.pop();
        if (d!=dist[x]) continue;  // ignoriram stare vrednosti
        // popravim potencialne razdalje
        for (auto [y,w] : sosedi[x]) {
            int d=dist[x]+w;
            if (dist[y]==-1 || d<dist[y]) {
                dist[y]=d; prev[y]=x;
                pq.push({d,y});
            }
        }
    }
}

int main() {
    /*
    ifstream fin("critical.txt");
    int n,m;
    fin >> n >> m;
    vector<vector<int>> sosedi(n);
    vector<vector<PII>> sosediW(n);
    for (int i=0;i<m;i++) {
        int a,b,c;
        fin >> a >> b >> c;
        sosedi[a].push_back(b);
        sosediW[a].push_back({b,c});
    }
    for (int x=0;x<n;x++) {
        cout << x << ": ";
        print(sosedi[x]);
    }
    // kriticna pot
    vector<int> topo = toposort(sosedi);
    reverse(topo.begin(), topo.end());
    vector<int> d(n), nxt(n);
    for (int x : topo) {
        for (auto [y,w] : sosediW[x]) {
            if (w+d[y] > d[x]) {
                d[x] = w+d[y];
                nxt[x] = y;
            }
        }
    }
    print(d);
    int start=0;
    for (int x=0;x<n;x++) {
        if (d[x]>d[start]) start=x;
    }
    while (d[start]>0) {
        cout << start << " ";
        start = nxt[start];
    }
    cout << start << endl;
    */
    
    ifstream fin("weighted.txt");
    int n,m;
    fin >> n >> m;
    vector<vector<PII>> sosedi(n);
    for (int i=0;i<m;i++) {
        int a,b,c;
        fin >> a >> b >> c;
        sosedi[a].push_back({b,c});
        sosedi[b].push_back({a,c});
    }
    /*
    for (int x=0;x<n;x++) {
        printf("%d: ",x);
        for (auto [y,w] : sosedi[x]) printf(" (%d,%d)",y,w);
        printf("\n");
    }
    */
    vector<int> dist, prev;
    Dijsktra(sosedi, 0, dist, prev);
    print(dist);
    print(prev);
    int x=5;
    while (x!=0) {
        cout << x << " ";
        x=prev[x];
    }
    cout << 0 << endl;

    DijsktraPQ(sosedi, 0, dist, prev);
    print(dist);
    print(prev);
    return 0;
}
