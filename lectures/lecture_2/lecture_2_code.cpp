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

void selection_sort(vector<int> &sez) {
    int n=sez.size();
    for (int i=0; i<n; i++) {
        int m=i;
        for (int j=i;j<n;j++) {
            if (sez[j] < sez[m]) m = j;
        }
        swap(sez[i], sez[m]);
    }
}

void insertion_sort(vector<int> &sez) {
    int n=sez.size();
    for (int i=1;i<n;i++) {
        int x=sez[i];
        int j=i-1;
        while (j>=0 && sez[j]>x) {
            sez[j+1] = sez[j];
            j--;
        }
        sez[j+1] = x;
    }
}

void bubble_sort(vector<int> &sez) {
    int n=sez.size();
    bool change=true;
    while (change) {
        change = false;
        for (int i=0;i+1<n;i++) {
            if (sez[i]>sez[i+1]) {
                swap(sez[i], sez[i+1]);
                change = true;
            }
        }
    }
}

void bubble_sort_n(vector<int> &sez) {
    int n=sez.size();
    for (int it=0;it<n;it++) {
        for (int i=0;i+1<n;i++) {
            if (sez[i]>sez[i+1]) {
                swap(sez[i], sez[i+1]);
            }
        }
    }
}

vector<int> merge(vector<int> &a, vector<int> &b) {
    int i=0, j=0;
    vector<int> c;
    while (i<a.size() || j<b.size()) {
        if (i<a.size() && j<b.size()) {
            if (a[i]<b[j]) c.push_back(a[i++]);
            else c.push_back(b[j++]);
        } else if (i<a.size()) c.push_back(a[i++]);
        else c.push_back(b[j++]);
    }
    return c;
}

vector<int> merge_sort(vector<int> &sez) {
    int n=sez.size();
    if (n<=1) return sez;
    vector<int> levo(sez.begin(), sez.begin()+n/2);
    vector<int> desno(sez.begin()+n/2, sez.end());
    levo = merge_sort(levo);
    desno = merge_sort(desno);
    return merge(levo, desno);
}

int main() {
    //vector<int> sez = {9,4,2,8,7,5};
    //selection_sort(sez);
    //insertion_sort(sez);
    //bubble_sort(sez);
    //bubble_sort_n(sez); 
    //sez = merge_sort(sez);
    vector<int> sez;
    default_random_engine rnd(123);
    for (int i=0;i<1000000;i++) sez.push_back(rnd()%1000000);
    //insertion_sort(sez);
    sez = merge_sort(sez);
    return 0;
}
