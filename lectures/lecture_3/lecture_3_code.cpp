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

array<vector<int>,3> partition(vector<int> sez) {
    int pivot = sez[0];
    vector<int> majhni, enaki, veliki;
    for (int x : sez) {
        if (x<pivot) majhni.push_back(x);
        else if (x>pivot) veliki.push_back(x);
        else enaki.push_back(x);
    }
    return {majhni, enaki, veliki};
}

vector<int> quicksort(vector<int> sez) {
    if (sez.size()<=1) return sez;
    auto [majhni, enaki, veliki] = partition(sez);
    auto urejeni_majhni = quicksort(majhni);
    auto urejeni_veliki = quicksort(veliki);
    vector<int> rez;
    for (int x : urejeni_majhni) rez.push_back(x);
    for (int x : enaki) rez.push_back(x);
    for (int x : urejeni_veliki) rez.push_back(x);
    return rez;
}


bool bisekcija_narobe(vector<int> sez, int x) {
    int levo=0, desno=sez.size()-1;
    while (1) {
        int i=(levo+desno)/2;
        if (x < sez[i]) desno = i-1;
        else levo = i+1;
        if (sez[i]==x || desno<levo) break;
    }
    return levo <= desno;
}

int bisekcija(vector<int> &sez, int x) {
    int l=-1, r=sez.size();
    while (r-l>1) {
        int m=(l+r)/2;
        if (sez[m] < x) l=m;
        else r=m;
    }
    return r;
}

class DynamicArray {
private:
    int *t, size, capacity;
public:
    DynamicArray() {
        size=0; capacity=1;
        t = (int*)malloc(sizeof(int));
    }
    ~DynamicArray() { free(t); }
    int operator[](int i) { return t[i]; }
    void add(int x) {
        if (size==capacity) {
            capacity *= 2;
            t = (int*)realloc(t, capacity*sizeof(int));
        }
        t[size++] = x;
    }
};

int main() {
    DynamicArray a;
    int n=1'000'000;
    for (int i=0;i<n;i++) a.add(3*i);
    cout << a[n/2] << endl;

    /*
    vector<int> sez={2,3,3,3,9,15,15,15,30,100};
    cout << bisekcija(sez, 15) << endl;
    cout << bisekcija(sez, 1) << endl;
    cout << bisekcija(sez, 999) << endl;

    cout << lower_bound(sez.begin(),sez.end(),15) - sez.begin() << endl;
    cout << upper_bound(sez.begin(),sez.end(),15) - sez.begin() << endl;

    vector<int> s = quicksort({4,6,2,3,0,7,8,9});
    print(s);
    
    vector<int> sez;
    default_random_engine rnd(123);
    for (int i=0;i<1000000;i++) sez.push_back(rnd()%1'000'000);
    sez = quicksort(sez);
    cout << is_sorted(sez.begin(), sez.end()) << endl;
    */
    return 0;
}
