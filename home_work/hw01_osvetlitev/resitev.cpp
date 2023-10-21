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

    // The first lamp to calculate the diff from the start
    lamps.push_back(make_pair(0, 0));

    int a, b;
    
    for (int i = 0; i < n; i++) {

        // Scan the location of the lamp and its strength
        cin >> a >> b;

        // Store the interval length that we calculate from the lamp location and strength
        lamps.push_back(make_pair(a - b, a + b));
    }

    // The last lamp to calculate the diff from the end
    lamps.push_back(make_pair(m, m));

    // Sort our vector of pairs
    sort(lamps.begin(), lamps.end());

    //for (pair<int, int> interval : lamps) cout << "[" << interval.first << ", " << interval.second << "]" << endl;

    int i = 0;
    int sum = 0;
    int diff;
    
    while (i != n + 1) {

        if (lamps[i + 1].second <= lamps[i].second) {
            lamps[i + 1] = lamps[i];
            i++;
            continue;
        }

        diff = lamps[i+1].first - lamps[i].second;

        if (diff > 0) {
            sum += diff;
        }

        i++;
    }

    cout << sum << endl;
}

