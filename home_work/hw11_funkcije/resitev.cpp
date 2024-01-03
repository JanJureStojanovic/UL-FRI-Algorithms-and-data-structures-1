#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>

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

void print2(const vector<PII> &sez) {
    for (PII x : sez) cout << x.second << " ";
    cout << endl;
}

long f(long x, float i, int &st_funkcij){
    return long(x * pow(log2(x), i/st_funkcij));
}

vector<long> bisection(vector<long> sez, long iskana, long lo, long hi, int st_funkcij){
    long last = f(hi, float(sez[4]), st_funkcij);
    long first = f(lo, float(sez[4]), st_funkcij);
    long mid = f((lo+hi)/2, float(sez[4]), st_funkcij);
    if (iskana > last){
        vector<long> s = {sez[3]-sez[2]+1, 0};
        return s;
    }
    if (iskana < first){
        vector<long> s = {0, 0};
        return s;
    }
    while(lo+1 < hi){
        if (iskana < mid){
            hi = (lo+hi)/2;
        }
        if (iskana >= mid){
            lo = (lo+hi)/2;
        }
        mid = f((lo+hi)/2, float(sez[4]), st_funkcij);
    }
    long a = lo-sez[2]+1; long b = 0;
    while (iskana == mid && mid >= first){
        b++;
        mid = f(--lo, float(sez[4]), st_funkcij);
    }
    vector<long> s = {a, b};
    return s;

}

int main(){
    int st_funkcij; long k;
    long max = 1;
    long min = LONG_MAX; 
    cin >> st_funkcij >> k;

    vector<vector<long>> ranges;
    for (int i=1; i<=st_funkcij; i++){
        long a, b;
        cin >> a >> b;
        long mi, ma;
        mi = f(a, float(i), st_funkcij);
        ma = f(b, float(i), st_funkcij);
        ranges.push_back({mi, ma, a, b, i});
        if (max < ma){
            max = ma;
        }
        if (min > mi){
            min = mi;
        }
    }
    long mid = (min+max)/2;
    long manjsih = 0;
    long enakih = 0;
    while(min+1 < max){
        mid = (min+max)/2;
        manjsih = 0;
        enakih = 0;
        //printf("min: %ld max: %ld\n", min, max);
        printf("mid: %ld\n", mid);
        for(auto sez: ranges){
            //printf("I: %ld\n", sez[4]);
            vector<long> a = bisection(sez, mid, sez[2], sez[3], st_funkcij);
            manjsih += a[0];
            enakih += a[1];
            //printf("manjsihenakih: %ld enakih: %ld\n", a[0], a[1]);
        }
        printf("--manjsihenakih: %ld enakih: %ld\n", manjsih, enakih);
        if (manjsih >= k){
            max = mid;
        }

        if (manjsih < k){
            min = mid;
        }

    }
    printf("K-mansj: %ld\n", k-manjsih);
    printf("manjsihenakih: %ld enakih: %ld\n", manjsih, enakih);
    printf("min: %ld max: %ld\n", min, max);
    if (enakih){
        printf("%ld\n", max);
    }else{
        printf("%ld\n", min);
    }
    //neki z temu kolk je istih pa manjsih??
    /*
    vector<long> all;
    for (auto sez: ranges){
        for(long x=sez[2]; x<=sez[3]; x++){
            all.push_back(f(x, float(sez[4]), st_funkcij));
        }
    }
    sort(all.begin(), all.end());
    printf("%ld\n", all[k-1]);
    print(all);
    printf("k: %ld\n", k);
    */

    return 0;
}