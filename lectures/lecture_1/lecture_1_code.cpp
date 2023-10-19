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

void izpis(vector<int> &sez) {
    //sez.push_back(99);
    for (int x : sez) cout << x << " ";
    cout << endl;
}

int uredi_perm(vector<string> &sez) {
    int n=sez.size();
    vector<int> p;
    int st=0;
    for (int i=0;i<n;i++) p.push_back(i);
    do {
        st++;
        vector<string> urejen(n);
        for (int i=0;i<n;i++) {
            urejen[i] = sez[p[i]];
        }
        bool je_urejen = true;
        for (int i=0;i+1<n;i++) {
            if (urejen[i] > urejen[i+1]) je_urejen = false;
        }
        if (je_urejen) {
            sez = urejen;
            break;
        }
    } while (next_permutation(p.begin(),p.end()));
    return st;
}

int uredi_rand(vector<string> &sez) {
    int n=sez.size();
    default_random_engine rnd;
    int st=0;
    while (1) {
        st++;
        shuffle(sez.begin(),sez.end(),rnd);
        bool je_urejen = true;
        for (int i=0;i+1<n;i++) {
            if (sez[i] > sez[i+1]) je_urejen = false;
        }
        if (je_urejen) break;
    }
    return st;
}

int main() {
    vector<string> sez = {"Miha", "Vid", "Ana", "Tine", "Jan", "Jure"};
    int st1=0,st2=0;
    default_random_engine rnd(123);
    for (int it=0;it<100;it++) {
        shuffle(sez.begin(),sez.end(),rnd);
        auto s1 = sez;
        auto s2 = sez;
        st1 += uredi_perm(s1);
        st2 += uredi_rand(s2);
    }
    cout << st1/100.0 << " " << st2/100.0 << endl;
    /*
    // reference
    int x=10;
    int &y=x;
    cout << x << " " << y << endl;
    x=20;
    cout << x << " " << y << endl;
    y=30;
    cout << x << " " << y << endl;

    vector<int> v={1,2,3,4};
    izpis(v);
    cout << v.size() << endl;

    cout << min(5,2) << endl;
    cout << min({3,6,1,2}) << endl;

    vector<int> v = {3,7,9,4};
    cout << *min_element(v.begin(),v.end()) << endl;
    vector<int>::iterator it = min_element(v.begin(),v.end());
    cout << "x" << (it==v.begin()) << endl;

    sort(v.begin(),v.end());
    for (int x : v) cout << x << " ";
    cout << '\n';
    //cout << endl;

    
    map<string,int> vpisna = {{"Ana",123},{"Miha",456}};
    //vpisna["Ana"] = 123;
    //vpisna["Miha"] = 456;
    cout << vpisna["Ana"] << endl;
    cout << vpisna["Jan"] << endl;
    for (auto [ime, st] : vpisna) {
        cout << ime << " " << st << endl;
    }

    vector<int> v = {0,0,0,0};
    for (int x=1;x<=1024;x*=2) v.push_back(x);
    for (int i=0;i<v.size();i++) cout << v[i] << " ";
    cout << endl;

    // iteratorji
    //for (vector<int>::iterator it=v.begin(); it!=v.end(); it++) {
    for (auto it=v.begin(); it!=v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // for each
    for (int x : v) cout << x << " ";
    cout << endl;

    vector<pair<int,int>> koordinate = {{2,3}, {-1,3}, {4,0}};
    //for (pair<int,int> xy : koordinate) {
    for (auto xy : koordinate) {
        cout << "[" << xy.first << ", " << xy.second << "]" << endl;
    }
    for (auto [x, y] : koordinate) {
        cout << "[" << x << ", " << y << "]" << endl;
    }

    array<int,3> a = {2,4,6};
    auto [x,y,z] = a;
    cout << x << y << z << endl;


    pair<int,string> xy = {10, "Ana"};
    //xy = make_pair(10, "Ana");
    cout << xy.first << " " << xy.second << endl;

    pair<pair<int,int>, string> trojica = {{1,2}, "Ana"};
    auto kopija = trojica;  // kopija po vrednosti
    kopija.second = "Miha";
    //trojica = make_pair(make_pair(1,2), "Ana");
    cout << trojica.second << " " << trojica.first.first << " "
         << trojica.first.second << endl;

    array<int, 3> a = {10,20,30};
    //a[0]=10; a[1]=20; a[2]=30;
    cout << a[1] << endl;
    
    string a,b;
    cin >> a >> b;
    cout << "Vsota: " << a + b << endl;
    cout << a[0] << b[0] << endl;
    cout << a.size() << endl;
    */
    return 0;
}
