#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    // Our straight length and number of lamps
    int m, n;
    cin >> m >> n;

    // Array of pairs holding the location of all lamps and their corresponding lengths
    vector<pair<int, int>> lamps;
    
    for (int i = 0; i < n; i++) {
        // We scan the location of the lamp and its strength
        int l, r;
        cin >> l >> r;

        // We calculate our intrval (resetting intervals if neccessary)
        int start = (l - r < 0) ? 0 : l - r;
        int end = (l + r > m) ? m : l + r;

        // We store the interval length that we calculate from the lamp location and strength
        lamps.push_back(make_pair(start, end));
    }

    // We sort our vector of pairs
    sort(lamps.begin(), lamps.end());

    for (pair<int, int> interval : lamps) cout << "[" << interval.first << ", " << interval.second << "]" << endl;

    for (auto it = lamps.begin(); it != lamps.end();) {
        if (next(it) != lamps.end() && it->second >= next(it)->second) {
            it = lamps.erase(next(it));
        } else {
            ++it;
        }
    }

    for (pair<int, int> interval : lamps) cout << "[" << interval.first << ", " << interval.second << "]" << endl;

    int sum = 0;

    int spredaj = m;
    int zadaj = m;

    for (int i = 0; i < lamps.size() - 1; i++) {

        // Beggining and end check
        int kandidat_spredaj = lamps[i].first;
        if (kandidat_spredaj < spredaj) spredaj = kandidat_spredaj;
        int kandidat_zadaj = m - lamps[i].second;
        if (kandidat_zadaj < zadaj) zadaj = kandidat_zadaj;

        if (lamps[i+1].first - lamps[i].second > 0) sum += lamps[i+1].first - lamps[i].second;
        
    }

    int kandidat_spredaj = lamps.back().first;
    if (kandidat_spredaj < spredaj) spredaj = kandidat_spredaj;
    int kandidat_zadaj = m - lamps.back().second;
    if (kandidat_zadaj < zadaj) zadaj = kandidat_zadaj;

    if (spredaj < 0) spredaj = 0;
    if (zadaj < 0) spredaj = 0;
    
    cout << sum + spredaj + zadaj << endl;
}

// UGOTOVITEV: ODSTRANI INTERVALE, KI SO ZNOTRAJ ENEGA INTERVALA! Ce je lamps[i].second >= lamps[i+1].second -> remove lamps[i+1]

/*
int m, n;
cin >> m >> n;

int[m] arr;
    
for (int i = 0; i < n; i++) {
    
    // Lamp location and length 
    int a, b;
    cin >> a >> b;

    // Interval [start, finish)
    int start = a - b;
    int finish = a + b;

    if (start < 0) start = 0;
    if (finish > m) finish = m;

    for (int j = start; j < finish; j++) {
        arr[j] = 7;
    }
}

// Sum of non 7 array values 
int sum = 0;

for (int i = 0; i < m; i++) {
    //cout << arr[i] << " ";
    if (arr[i] != 7) sum++;
}
//cout << std::sendl;
cout << sum << std::endl;
*/