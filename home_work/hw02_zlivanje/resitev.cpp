// Second home work


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    // Parameters
    int n, k, a;
    cin >> n >> k >> a;

    // Vector that holds ascending subsets
    vector<vector<int>> cete;

    int x, y;

    cin >> x;

    for (int i = 0; i < n; i++) {

        vector<int> ceta;

        for (int j = i; j < n; j++) {

            cin >> y;

            // Imamo dva sosednja clena zaporedja x in y

            // x < y: Dodamo x v trenutni vektor in x prevzame vrednost y 
            if (x <= y) {
                ceta.push_back(x);
                x = y;
                continue;
            }
            // x > y: Dodamo vektor s podzaporedjem v glavni vektor in naredimo novi vektor za novo podazaporedje    
            if (x > y) {
                ceta.push_back(x);
                cete.push_back(ceta);
                x = y;
                i = j;
                break;
            }  
        }
    }

    for (int i = 0; i < cete.size(); i++) {
        for (int j = 0; j < cete[i].size(); j++) {
            cout << cete[i][j] << " ";
        }
        cout << endl;
    }
}