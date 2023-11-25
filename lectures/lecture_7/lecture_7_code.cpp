#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> PII;
typedef vector<pair<int,int>> VII;

VII aktivnosti (VII a) {
    VII razpored;
    int konec=0;
    while (1) {
        int j=-1;
        for (int i=0;i<a.size();i++) {
            if (konec <= a[i].first) {  // relevanten?
                if (j==-1 || a[i].second<a[j].second) j=i;  // boljsi?
            }
        }
        if (j==-1) break;
        razpored.push_back(a[j]);
        konec = a[j].second;
    }
    return razpored;
}

bool cmpSecond(PII x, PII y) {  // x < y
    return x.second < y.second;
}

VII aktivnosti2(VII a) {
    sort(a.begin(),a.end(),cmpSecond);
    VII razpored;
    int konec=0;
    for (auto [s,e] : a) {
        if (konec <= s) {
            razpored.push_back({s,e});
            konec = e;
        }
    }
    return razpored;
}

vector<VII> predavalnice(VII predavanja) {
    sort(predavanja.begin(), predavanja.end());
    vector<VII> urnik;
    priority_queue<PII, vector<PII>, greater<PII>> pq;  // min-heap
    pq.push({predavanja.back().second, -1});  // dummy
    for (auto p : predavanja) {
        auto [s,e] = p;
        auto [konec, x] = pq.top();
        if (konec<=s) {
            pq.pop(); pq.push({e,x});
            urnik[x].push_back(p);
        } else {
            pq.push({e,urnik.size()});
            urnik.push_back({p});
        }
    }
    return urnik;
}

int score(VII d) {
    int x=0, sc=0;
    for (auto [s,f] : d) {
        sc+=x*f;
        x+=s;
    }
    return sc;
}

bool cmpRatio(PII x, PII y) {  // x < y
    //return x.first/x.second < y.first/y.second;
    //return (double)x.first/x.second < (double)y.first/y.second;
    return (long long)x.first*y.second < (long long)y.first*x.second;
}

int trak(VII d) {
    sort(d.begin(),d.end(),cmpRatio);
    return score(d);
}

int main() {
    VII d = {{60,5}, {27,3}, {1,20}, {32,4}};
    cout << trak(d) << endl;
    sort(d.begin(),d.end());
    do {
        cout << score(d) << " ";
    } while (next_permutation(d.begin(),d.end()));
    cout << endl;
    /*
    VII predavanja = {{4,10}, {12,15}, {0,3}, {4,7}, {8,11}, {0,7}, {10,15}, {0,3}, {8,11}, {12,15}};
    vector<VII> urnik = predavalnice(predavanja);
    for (auto ucilnica : urnik) {
        for (auto [s,e] : ucilnica) printf("[%d,%d] ",s,e);
        printf("\n");
    }
    */
    /*
    VII a = {{1,3},{2,4},{2,5},{4,5},{4,7},{6,7},{6,8},{7,12},{8,12},{9,10},{9,11},{11,12},{12,13}};
    //VII r = aktivnosti(a);
    VII r = aktivnosti2(a);
    printf("%d:",(int)r.size());
    for (auto [s,e] : r) printf(" [%d,%d]",s,e);
    printf("\n");
    */
    return 0;
}
