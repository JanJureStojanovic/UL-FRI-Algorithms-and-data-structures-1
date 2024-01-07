#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// Preverimo ce se zemljisci prekrivata -> ce se, je razdalja takoj 0
bool prekrivanje(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    if ((x1 >= x3 && x1 <= x4 && y1 >= y3 && y1 <= y4) ||
        (x2 >= x3 && x2 <= x4 && y2 >= y3 && y2 <= y4)) { // Prvo zemljisce znotraj drugega
        return true;
    }
    if ((x3 >= x1 && x3 <= x2 && y3 >= y1 && y3 <= y2) ||
        (x4 >= x1 && x4 <= x2 && y4 >= y1 && y4 <= y2)) { // Drugo zemljisce znotraj prvega
        return true;
    }
    return false; // Sicer
}

int main() {

    // St. primerov
    int t;
    cin >> t;

    // Podatki o zemljiscih in spremenljivki, ki bosta hranili njihovo velikost
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int size1, size2;

    // Main for loop, cez vso stevilo primerov
    for (int i = 0; i < t; i++) {

        // Min
        int curr_min = 800000;
        // Input data
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        // Uredimo tocke (T1 - levo spodaj, T2 desno zgoraj in T3 levo spodaj in T4 desno zgoraj) -> Se vedno opisujemo isto zemljisce
        if (x1 > x2 && y1 > y2) { // Zamenjamo jih med sabo (x2 -> x1 in x1 -> x2)
            int temp_x = x1;
            int temp_y = y1;
            x1 = x2;
            y1 = y2;
            x2 = temp_x;
            y2 = temp_y;
        } else if (x1 > x2 && y1 < y2) { // Visine so ok, spremenimo x-a
            int temp_x = x1;
            x1 = x2;
            x2 = temp_x;
        } else if (x1 < x2 && y1 > y2) {
            int temp_y = y1;
            y1 = y2;
            y2 = temp_y;
        }

        // Size comparison
        size1 = abs((x2 - x1)*(y2 - y1));
        size2 = abs((x4 - x3)*(y4 - y3));

        // Ce imamo prekrivanje takoj output 0
        if (prekrivanje(x1, y1, x2, y2, x3, y3, x4, y4) == true) {
            cout << 0 << "\n";
            continue;
        }
        cout << curr_min << "\n";

        // Iscemo razdalje, ce sta zemljisci v skupnem pasu
        // Najdemo vecje zemljisce in pogledamo ce sta v skupnih pasovih (x-os in y-os)
        if (size1 > size2) {
            // Pas po x-osi
            // Spodnji rob manjsega zemljisca znotraj pasu vecjega zemljisca
            if (y3 >= y1 && y3 <= y2) {
                curr_min = curr_min < abs(x1 - x4)*8 ? curr_min : abs(x1 - x4)*8; // Manjse zemljisce je levo
                cout << curr_min << "\n";
                curr_min = curr_min < abs(x3 - x2)*8 ? curr_min : abs(x3 - x2)*8; // Manjse zemljisce je desno
                cout << curr_min << "\n";
            }
            // Zgornji rob manjsega zemljisca znotraj pasu vecjega zemljisca
            if (y4 >= y1 && y4 <= y2) {
                curr_min = curr_min < abs(x1 - x4)*8 ? curr_min : abs(x1 - x4)*8; // Manjse zemljisce je levo
                cout << curr_min << "\n";
                curr_min = curr_min < abs(x3 - x2)*8 ? curr_min : abs(x3 - x2)*8; // Manjse zemljisce je desno
                cout << curr_min << "\n";
            }
            // Pas po y-osi
            // Levi rob manjsega zemljisca znotraj pasu vecjega zemljisca
            if (x3 >= x1 && x3 <= x2) {
                curr_min = curr_min < abs(y1 - y4)*8 ? curr_min : abs(y1 - y4)*8; // Manjse zemljisce je spodaj
                cout << curr_min << "\n";
                curr_min = curr_min < abs(y3 - y2)*8 ? curr_min : abs(y3 - y2)*8; // Manjse zemljisce je zgoraj  
                cout << curr_min << "\n";           
            }
            // Desni rob manjsega zemljisca znotraj pasu vecjega zemljisca
            if (x4 >= x1 && x4 <= x2) {
                curr_min = curr_min < abs(y1 - y4)*8 ? curr_min : abs(y1 - y4)*8; // Manjse zemljisce je spodaj
                cout << curr_min << "\n";
                curr_min = curr_min < abs(y3 - y2)*8 ? curr_min : abs(y3 - y2)*8; // Manjse zemljisce je zgoraj
                cout << curr_min << "\n";
            }
        // Menjava spremenljivk
        } else {
            // Pas po x-osi
            // Spodnji rob manjsega zemljisca znotraj pasu vecjega zemljisca
            if (y1 >= y3 && y1 <= y4) {
                curr_min = curr_min < abs(x3 - x2)*8 ? curr_min : abs(x3 - x2)*8; // Manjse zemljisce je levo
                cout << curr_min << "\n";
                curr_min = curr_min < abs(x1 - x4)*8 ? curr_min : abs(x1 - x4)*8; // Manjse zemljisce je desno
                cout << curr_min << "\n";
            }
            // Zgornji rob manjsega zemljisca znotraj pasu vecjega zemljisca
            if (y2 >= y3 && y2 <= y4) {
                curr_min = curr_min < abs(x3 - x2)*8 ? curr_min : abs(x3 - x2)*8; // Manjse zemljisce je levo
                cout << curr_min << "\n";
                curr_min = curr_min < abs(x1 - x4)*8 ? curr_min : abs(x1 - x4)*8; // Manjse zemljisce je desno
                cout << curr_min << "\n";
            }
            // Pas po y-osi
            // Levi rob manjsega zemljisca znotraj pasu vecjega zemljisca
            if (x1 >= x3 && x1 <= x4) {
                curr_min = curr_min < abs(y4 - y1)*8 ? curr_min : abs(y4 - y1)*8; // Manjse zemljisce je spodaj
                cout << curr_min << "\n";
                curr_min = curr_min < abs(y2 - y3)*8 ? curr_min : abs(y2 - y3)*8; // Manjse zemljisce je zgoraj  
                cout << curr_min << "\n";           
            }
            // Desni rob manjsega zemljisca znotraj pasu vecjega zemljisca
            if (x2 >= x3 && x2 <= x4) {
                curr_min = curr_min < abs(y4 - y1)*8 ? curr_min : abs(y4 - y1)*8; // Manjse zemljisce je spodaj
                cout << curr_min << "\n";
                curr_min = curr_min < abs(y2 - y3)*8 ? curr_min : abs(y2 - y3)*8; // Manjse zemljisce je zgoraj 
                cout << curr_min << "\n";
            }
        }

        // Ce nista v istih pasovih (ni prekrivanja) -> pitagorov izrek
        // Zemljisce ena v sredini in zemljisce dve okoli
        curr_min = curr_min < ((sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)))*8) ? 
                   curr_min : ((sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)))*8); // Desno zgoraj
                   cout << curr_min << "\n";
        curr_min = curr_min < ((sqrt((x3 - x2)*(x3 - x2) + (y1 - y4)*(y1 - y4)))*8) ?
                   curr_min : ((sqrt((x3 - x2)*(x3 - x2) + (y1 - y4)*(y1 - y4)))*8); // Desno spodaj
                   cout << curr_min << "\n";
        curr_min = curr_min < ((sqrt((x1 - x4)*(x1 - x4) + (y3 - y2)*(y3 - y2)))*8) ?
                   curr_min : ((sqrt((x1 - x4)*(x1 - x4) + (y3 - y2)*(y3 - y2)))*8); // Levo zgoraj
                   cout << curr_min << "\n";
        curr_min = curr_min < ((sqrt((x1 - x4)*(x1 - x4) + (y1 - y4)*(y1 - y4)))*8) ?
                   curr_min : ((sqrt((x1 - x4)*(x1 - x4) + (y1 - y4)*(y1 - y4)))*8); // Levo spodaj
                   cout << curr_min << "\n";
        // Zemljisce dve v sredini in zemljisce ena okoli
        curr_min = curr_min < ((sqrt((x1 - x4)*(x1 - x4) + (y1 - y4)*(y1 - y4)))*8) ? 
                   curr_min : ((sqrt((x1 - x4)*(x1 - x4) + (y1 - y4)*(y1 - y4)))*8); // Desno zgoraj
                   cout << curr_min << "\n";
        curr_min = curr_min < ((sqrt((x1 - x4)*(x1 - x4) + (y3 - y2)*(y3 - y2)))*8) ?
                   curr_min : ((sqrt((x1 - x4)*(x1 - x4) + (y3 - y2)*(y3 - y2)))*8); // Desno spodaj
                   cout << curr_min << "\n";
        curr_min = curr_min < ((sqrt((x3 - x2)*(x3 - x2) + (y1 - y4)*(y1 - y4)))*8) ?
                   curr_min : ((sqrt((x3 - x2)*(x3 - x2) + (y1 - y4)*(y1 - y4)))*8); // Levo zgoraj
                   cout << curr_min << "\n";
        curr_min = curr_min < ((sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)))*8) ?
                   curr_min : ((sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)))*8); // Levo spodaj
                   cout << curr_min << "\n";

        // Output minimum distance
        cout << ceil(curr_min) << "\n";
    }

    return 0;
}