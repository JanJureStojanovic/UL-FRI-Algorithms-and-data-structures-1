#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

class HashTable {
public:
    vector<vector<pair<int,int>>> t;  // [(k1,v1), (k2,v2), ...]
    int size, capacity;
    int hash(int x) { return x%capacity; }
    HashTable() { size=0; capacity=1; t.resize(capacity); }

    void rehash() {  // O(size + capacity)
        capacity*=2;
        vector<vector<pair<int,int>>> t2(capacity);
        for (int h=0;h<t.size();h++) {
            for (auto& [key, value] : t[h]) {
                int h2=hash(key);
                t2[h2].push_back({key,value});
            }
        }
        t = t2;
    }

    void insert(int k, int v) {
        if (size==capacity) rehash();
        int h=hash(k);
        for (auto& [key, value] : t[h]) {
            if (key==k) { value=v; return; }
        }
        t[h].push_back({k,v});
        size++;
    }

    int get(int k) {
        int h=hash(k);
        for (auto& [key, value] : t[h]) {
            if (key==k) { return value; }
        }
        return -1;
    }
};

int main() {
    default_random_engine rnd(1234);
    HashTable ht;
    int n=1500;
    for (int i=0;i<n;i++) {
        int k=rnd()%n;
        ht.insert(k, 1);
    }
    cout << ht.size << " " << ht.capacity << endl;
    double sum=0;
    int m=0;
    for (int h=0;h<ht.capacity;h++) {
        sum+=ht.t[h].size();
        m=max(m, (int)ht.t[h].size());
    }
    cout << sum/ht.capacity << " " << m << endl;
    return 0;
}
