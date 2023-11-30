#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    // Number of pairs
    int st_parov;
    cin >> st_parov;

    // Our pairs of strings
    string vzorec, niz;

    // Program end output (it will hold n pairs)
    vector<pair<int, int>> indeks_output;

    // Iteration over n amount of pairs
    for (int i = 0; i < 5; i++) {

        // Read the pairs
        cin >> vzorec >> niz;

        // Compare the pairs
        // For loop matching the sample string to the main string
        for (int j = 0; j < niz.length() - vzorec.length(); j++) {

            // Index going over the main string
            int l = j;

            // Index if we found mathching sample
            int zacetni_indeks = j;
            int koncni_indeks;

            // Bool to check if we found matching sample
            bool ujemanje_nizov = true;

            for (int k = 0; k < vzorec.lenght(); k++) {

                // If '?' we can move on
                if (vzorec[k] = '?') {
                    l++;
                    continue;
                }

                // We have to check all possibilities
                if (vzorec[k] = '*') {

                    /* Najprej probamo ce je lahko '*' prazen niz
                    Ce ne gre, nadaljujemo do prvega ujemanja (premikamo l, dokler k + 1 ni enak l)
                    Ce je vec ujemanj, moramo porobati vse (dvojni loop) */ 

                    int a = l;

                    // Premikamo se po nizu in iscemo ujemanje z znakom za '*'
                    while (a < niz.length() - vzorec.length()) { 

                        // Najdemo ujemanje znakov
                        if (vzorec[k+1] == niz[a]) {

                            // Nadaljujemo kot smo zaceli

                        }

                        // Premik po nizu
                        a++;

                    }
                }

                // Ni ujemanja -> gremo naprej po nizu
                if (vzorec[k] != niz[l]) {
                    
                    break;
                }

                l++;

            }
        }
    }
}