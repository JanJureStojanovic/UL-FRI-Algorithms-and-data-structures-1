#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adjw(n);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adjw[a].push_back({b,w});
        adjw[b].push_back({a,w});
    }
    
    return 0;
}