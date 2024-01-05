#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool prekrivanje(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    if ((x1 >= x3 && x1 <= x4 && y1 >= y3 && y1 <= y4) ||
        (x2 >= x3 && x2 <= x4 && y2 >= y3 && y2 <= y4)) {
        return true;
    }
    if ((x3 >= x1 && x3 <= x2 && y3 >= y1 && y3 <= y2) ||
        (x4 >= x1 && x4 <= x2 && y4 >= y1 && y4 <= y2)) {
        return true;
    }
    return false;
}

int main() {

    // St. primerov
    int t;
    cin >> t;

    int x1, y1, x2, y2, x3, y3, x4, y4;
    int size1, size2;

    for (int i = 0; i < t; i++) {

        // Min
        int curr_min = 100000;

        // Input data
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        // Size comparison
        size1 = abs((x2 - x1)*(y2 - y1));
        size2 = abs((x4 - x3)*(y4 - y3));

        // Ce imamo prekrivanje takoj output 0
        if (prekrivanje(x1, y1, x2, y2, x3, y3, x4, y4) == true) {
            cout << 0 << "\n";
            continue;
        }

        // Najdemo vecje zemljisce in pogledamo ce sta v skupnih pasovih (x-os in y-os)
        if (size1 > size2) {

            // Pas po x - osi
            if (y3 <= y2 && y3 >= y1) {
                // Smo znotraj vodoravnega pasu
                if ()
            }
            if (y4 >= y1 && y4 <= y2) {

            }



        }


    }

    
}