#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {

    multiset<int> vreca;

    int n, s, x;

    cin >> n;



    for (int i = 0; i < n; i++) {

        cin >> s >> x;

        // Dodajanje elementa v multimnozico
        if (s < 0) {
            vreca.insert(x);
            continue
        }

        // Odstranjevanje elementa iz multimnozice
        if (s = 0) {
            vreca.erase(x);

        }

        // Poizvedva cez multimnozico
        if (s > 0) {

        }



    }

    
}