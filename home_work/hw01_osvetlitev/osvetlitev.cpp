#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    // Straight length and number of lamps
    int m, n;
    cin >> m >> n;

    // Array of pairs holding the location of all lamps and their corresponding lengths
    vector<pair<int, int>> lamps;
    
    for (int i = 0; i < n; i++) {
        // Scan the location of the lamp and its strength
        int l, r;
        cin >> l >> r;

        // Calculate our intrval (resetting intervals if neccessary)
        int start = (l - r < 0) ? 0 : l - r;
        int end = (l + r > m) ? m : l + r;

        // Store the interval length that we calculate from the lamp location and strength
        lamps.push_back(make_pair(start, end));
    }

    // Sort our vector of pairs
    sort(lamps.begin(), lamps.end());

    //for (pair<int, int> interval : lamps) cout << "[" << interval.first << ", " << interval.second << "]" << endl;

    // Remove intervals inside of other intervals: ... (3, 9), (4, 6), (6, 8), ... -> ... (3, 9), ...
    for (auto it = lamps.begin(); it != lamps.end();) {
        if (next(it) != lamps.end() && it->second >= next(it)->second) {
            it = lamps.erase(next(it));
        } else {
            ++it;
        }
    }

    // Sum of unlit spots
    int sum = 0;

    /* 
    // Variables to check for unlit spots before the first lamp and after the last lamp
    int spredaj = m;
    int zadaj = m;
    */

    for (int i = 0; i < lamps.size() - 1; i++) {

        /* 
        // Beggining and end check
        if (lamps[i].first < spredaj) spredaj = lamps[i].first;
        if (m - lamps[i].second < zadaj) zadaj = m - lamps[i].second;
        */

        if (lamps[i+1].first - lamps[i].second > 0) sum += lamps[i+1].first - lamps[i].second;  
    }
    
    /* 
    // Beggining and end check on the last lamp
    if (lamps.back().first < spredaj) spredaj = lamps.back().first;
    if (m - lamps.back().second < zadaj) zadaj = m - lamps.back().second;
    */

    int front = (lamps.front().first < 0) ? 0 : lamps[0].first;
    int back = (lamps.back().second > m) ? 0 : m - lamps.back().second;
    
    cout << sum + front + back << endl;
}

