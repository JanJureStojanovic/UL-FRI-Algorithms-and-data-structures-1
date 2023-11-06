#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {

    multiset<int> vreca;

    // Scanned parameters
    int n, s, x;

    // For loop limits -> poizvedovanje
    int a, b;

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

            // Interval borders
            if (s > x) {
                a = s;
                b = x;
            } else {
                a = x; 
                b = s;
            }

            for (int i = a; i <= b; i++) {
                /*
                Somehow check if the element is in:
                Multiset {1, 2, 2, 3, 5, 6}, a = 1, b = 3:
                Contains 4 elements (1, 2, 2, 3)
                */
            }
        }



    }

    
}