#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> ujemanje (string vzorec, string niz);

int main() {

    int st_parov; // Number of pairs
    cin >> st_parov;

    string vzorec, niz; // Our pairs of strings

    vector<pair<int, int>> indeks_output; // Program end output (it will hold n pairs)

    // Iteration over n amount of pairs
    for (int i = 0; i < 5; i++) {

        cin >> vzorec >> niz; // Read the pairs

        // For loop matching the sample string to the main string
        for (int j = 0; j < niz.length() - vzorec.length(); j++) { 

            int zacetni_indeks = j; // Index if we found mathching sample
            int koncni_indeks;

            bool ujemanje_nizov = true; // Bool to check if we found matching sample

            // Compare the pairs (for each char in vzorec)
            for (int k = 0; k < vzorec.length(); k++) { 

                // Ni ujemanja -> gremo naprej po nizu
                if (vzorec[k] != niz[j + k]) {
                    ujemanje_nizov = false;
                    break;
                }

                // If '?' we can move on (imamo ujemanje)
                if (vzorec[k] = '?') { 
                    continue;
                }

                // We have to check all possibilities
                if (vzorec[k] = '*') {

                    int l = k + 1;
                    string naslednji_niz;

                    // Najdemo niz za '*' in pogledamo ce ga najdemo v glavnem nizu
                    while (vzorec[l] != '?' || vzorec[l] != '*') {
                        naslednji_niz = naslednji_niz + vzorec[l];
                        l++;
                    }

                    cout << naslednji_niz << endl;

                    /* 
                    for (int m = 0; m < niz.length() - naslednji_niz.length(); m++) {

                    }*/


                }

                k++; // Premik indeksa

            }
        }
    }
}

// Funkcija, ki najde prvo ujemanje (brez upostevanja '?' in '*')
pair<int, int> ujemanje(string vzorec, string niz) {

    int a, b;

    for (int i = 0; i < niz.length() - vzorec.length() + 1; i++) {

        a = i;
        b = i + vzorec.length() - 1;

        bool ujemanje = true;

        for (int j = 0; j < vzorec.length(); j++) {

            if (vzorec[j] != niz[i + j]) {
                ujemanje = false;
                break;
            }
        }

        if (ujemanje == true) {
            return make_pair(a, b);
        }
    }

    return make_pair(-1, -1);
}
