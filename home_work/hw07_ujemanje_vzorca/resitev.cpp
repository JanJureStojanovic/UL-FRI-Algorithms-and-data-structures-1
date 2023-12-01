#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> ujemanje (string vzorec, string niz);

int main() {

    //pair<int, int> primer = ujemanje("jan", "jurejan");
    //cout << primer.first << primer.second;

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
                if (vzorec[k] != niz[k + j]) {
                    ujemanje_nizov = false;
                    break;
                }

                // If '?' we can move on (imamo ujemanje)
                if (vzorec[k] = '?') { 
                    continue;
                }

                // We have to check all possibilities
                if (vzorec[k] = '*') {

                    int x = k + 1; // Vzamemo naslednjega za zvezdico
                    int y = j; // Vzamemo l-ti znak (kjer smo ostali)

                    // Najdemo niz, ki pride za '*' in iscemo ujemanje
                    while (y < vzorec.length()) {



                        y++;

                    }
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
