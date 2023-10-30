#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <algorithm>
#include <random>
using namespace std;

template<typename T>
void print(vector<T> sez) {
    for (T x : sez) cout << x << " ";
    cout << endl;
}

class BinaryHeap {
public:
    vector<int> t={-1};

    void push(int x) {
        t.push_back(x);
        int i=t.size()-1;
        while (i>1 && t[i]<t[i/2]) {
            swap(t[i],t[i/2]);
            i/=2;
        }
    }

    int pop() {
        int x=t[1], i=1;
        t[1]=t.back(); t.pop_back();
        while (1) {
            int j=i;
            int l=2*i, r=2*i+1;
            if (l<t.size() && t[l]<t[j]) j=l;
            if (r<t.size() && t[r]<t[j]) j=r;
            if (i==j) break;
            swap(t[j],t[i]);
            i=j;
        }
        return x;
    }
};

class SkipNode {
public:
    int value, height;
    vector<SkipNode*> next;
    SkipNode(int _value, int _height) : value(_value), height(_height) {
        next.resize(height);
    }
};

class SkipList {
    int max_height;
    SkipNode *head;
    default_random_engine rnd;
public:
    SkipList() : max_height(20) {
        head = new SkipNode(-1, max_height);
        rnd = default_random_engine(123);
    }
    ~SkipList() { delete head; }

    bool contains(int x) {
        SkipNode *node = head;
        for (int h=max_height-1; h>=0; h--) {
            while (node->next[h]!=NULL && node->next[h]->value < x) node = node->next[h];
        }
        return node->next[0]!=NULL && node->next[0]->value == x;
    }

    void insert(int x) {
        int height=1;
        while (height<max_height && rnd()%2==0) height++;
        SkipNode *new_node = new SkipNode(x, height);
        SkipNode *node = head;
        for (int h=max_height-1; h>=0; h--) {
            while (node->next[h]!=NULL && node->next[h]->value < x) node = node->next[h];
            if (h<height) {
                new_node->next[h] = node->next[h];
                node->next[h] = new_node;
            }
        }
    }
};

int main() {
    default_random_engine rnd(123);
    SkipList sl;
    int n=100'000, st=0;
    for (int i=0;i<n;i++) sl.insert(rnd()%n);
    for (int i=0;i<n;i++) st+=sl.contains(i);
    cout << st << endl;
    /*
    BinaryHeap h;
    default_random_engine rnd(123);
    int n=1000000;
    for (int i=0;i<n;i++) h.push(rnd()%1000000);
    vector<int> sez;
    for (int i=0;i<n;i++) sez.push_back(h.pop());
    if (is_sorted(sez.begin(),sez.end())) cout << "urejeno!" << endl;
    */
    return 0;
}
