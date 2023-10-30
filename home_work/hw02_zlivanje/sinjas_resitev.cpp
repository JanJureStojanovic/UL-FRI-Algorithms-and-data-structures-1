#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

    // faza spravljanja v cete!

    int n, k, a;
    cin >> n >> k >> a;
    int xi;

    vector<int> v;

    vector<vector<int>> cete;

    for(int i = 0; i < n; i++) {

        cin >> xi;
        v.push_back(xi);
    
    }

    vector<int> vstavljanje;
    vstavljanje.push_back(v[0]);
    
    for(int i = 1; i < n; i++) {

        if(v[i-1] <= v[i]) {
            vstavljanje.push_back(v[i]);
        } else {
            cete.push_back(vstavljanje);
            vstavljanje.clear();
            vstavljanje.push_back(v[i]);
        }

    }
    cete.push_back(vstavljanje);
    int m = cete.size();
    
    int ostanek = m % k;

    // mamo cete... faza zlivanja!

    vector<int> skupni;

    for(int korak = 0; korak < a; korak++) {
            
        for(int icet = 0; icet < m; icet = icet + pow(k,korak+1)) {

            skupni = cete[icet];

            for(int j = 1; j < k; j++) {

                if(icet + j*pow(k,korak) >= m) {
                    break;
                }

                skupni.insert(skupni.end(), cete[icet+j*pow(k,korak)].begin(), cete[icet+j*pow(k,korak)].end());

            }

        sort(skupni.begin(), skupni.end());
        cete[icet] = skupni;
        skupni.clear();
        
        }

    }

    for(int l = 0; l < m; l = l + pow(k,a)) {
        for(int s = 0; s < cete[l].size(); s ++) {
            cout << cete[l][s] << "\n";
        }
    }
    
        

}