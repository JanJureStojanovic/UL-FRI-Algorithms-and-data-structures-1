#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void izpis(vector<vector<int>> cete) {
    for (int i = 0; i < cete.size(); i++) {
        for (int j = 0; j < cete[i].size(); j++) {
            cout << cete[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> zlij(vector<vector<int>> cete, int k) { 

    // The new return vector
    vector<vector<int>> nove_cete;
        
    for (int i = 0; i < cete.size(); i += k) { 

        // Nova ceta, ki nastane iz k starih cet
        vector<int> nova_ceta;

        int nr_empty = 0;

        while(nr_empty != k) { // Ponavljamo dokler ne spraznemo vseh k cet

            nr_empty = 0; // Sproti preverjamo ali so vsi prazni
            
            int min_el = 2147483647; // Trenutni min element
            int ix; // Trenutni indeks vektorja, kateremu bomo odstranili prvi element
            int kandidat; // Kandida, ki lahko potenicalno zamenja trenutni najmanjsi element
            
            for (int j = i; j < i + k && j < cete.size(); j++) {
                
                if (cete[j].empty()) {
                    nr_empty++;
                } else {
                    kandidat = cete[j].front();
                    if (kandidat < min_el) {
                        min_el = kandidat;
                        ix = j;
                    }
                }  
            }
            
            if (nr_empty != k) { 
                // Imamo min_el
                nova_ceta.push_back(min_el);
                // Odstranimo min_el
                cete[ix].erase(cete[ix].begin());
            }    
        }

        // Dodamo eno novo ceto, ki je nastala iz k cet
        nove_cete.push_back(nova_ceta);
    }

    // Vrnemo vektor novih cet
    return nove_cete;
}

int main() {

    // Parameters
    int n, k, a;
    cin >> n >> k >> a;

    // Vector that holds ascending subsets
    vector<vector<int>> cete;

    int x, y; // The two neighbouring numbers
    cin >> x;

    for (int i = 0; i < n - 1; i++) {

        vector<int> ceta;
        cete.push_back(ceta);

        for (int j = i; j < n - 1; j++) {

            i++; // Moving the i along

            // We scan the next number -> we have two options
            cin >> y;
            
            // 1st option: x <= y
            if (x <= y) {
                cete.back().push_back(x);
                x = y;
            }

            // 2nd option: x > y
            if (x > y) {
                cete.back().push_back(x);
                x = y;
                break;
            }
        }

        i--; // Decrement of one needed since the for loop adds one
    }

    cete.back().push_back(y); // Add the forgotten element

    cout << endl;

    // Now that we have a vector of vectors we can sort it accordingly
    for (int i = 0; i < a; i++) { // The amount of times we sort the main vector
        
        izpis(cete);
        cout << endl;

        cete = zlij(cete, k);

        // Preverimo ce je celoten array sorted
    }
}