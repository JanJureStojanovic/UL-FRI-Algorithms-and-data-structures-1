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

    // Now that we have a vector of vectors we can sort it accordingly

    for (int i = 0; i < a; i++) { // The amount of times we sort the main vector

        for (int j = 0; j < cete.size(); j += k) { // The number of subset vectors we merge

        }
    }









    /*for (int i = 0; i < cete.size(); i++) {
        for (int j = 0; j < cete[i].size(); j++) {
            cout << cete[i][j] << " ";
        }
        cout << endl;
    }*/
}