#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// Preverimo prekrivanje pravokotnikov
bool prekrivanje(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {

    if (x1 > x4 || x3 > x2) {
        return false;
    }
    if (y1 > y4 || y3 > y2) {
        return false;
    }
    return true;
}

int main() {

    // St. primerov
    int t;
    cin >> t;

    // Podatki o zemljiscih in spremenljivki, ki bosta hranili njihovo velikost
    int x1, y1, x2, y2, x3, y3, x4, y4;

    // Main for loop, cez vso stevilo primerov
    for (int i = 0; i < t; i++) {

        // Min
        double curr_min = 800000.0;
        // Input data
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        // Uredimo tocke prvega zemljisca (T1 - levo spodaj, T2 desno zgoraj in T3 levo spodaj in T4 desno zgoraj)
        if (x1 >= x2 && y1 >= y2) { // Zamenjamo jih med sabo (x2 -> x1 in x1 -> x2)
            int temp_x = x1;
            int temp_y = y1;
            x1 = x2;
            y1 = y2;
            x2 = temp_x;
            y2 = temp_y;
        } else if (x1 >= x2 && y1 <= y2) { // Visine so ok, spremenimo x-a
            int temp_x = x1;
            x1 = x2;
            x2 = temp_x;
        } else if (x1 <= x2 && y1 >= y2) {
            int temp_y = y1;
            y1 = y2;
            y2 = temp_y;
        }
        // Uredimo tocke drugega zemljisca (T1 - levo spodaj, T2 desno zgoraj in T3 levo spodaj in T4 desno zgoraj)
        if (x3 >= x4 && y3 >= y4) { // Zamenjamo jih med sabo (x4 -> x3 in y4 -> y3)
            int temp_x = x3;
            int temp_y = y3;
            x3 = x4;
            y3 = y4;
            x4 = temp_x;
            y4 = temp_y;
        } else if (x3 >= x4 && y3 <= y4) { // Visine so ok, spremenimo x-a
            int temp_x = x3;
            x3 = x4;
            x4 = temp_x;
        } else if (x3 <= x4 && y3 >= y4) {
            int temp_y = y3;
            y3 = y4;
            y4 = temp_y;
        }

        // cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

        // Ce imamo prekrivanje takoj output 0
        if (prekrivanje(x1, y1, x2, y2, x3, y3, x4, y4) == true) {
            cout << 0 << "\n";
            continue;
        }

        // Iscemo razdalje, ce sta zemljisci v skupnem pasu
        if ((x1 >= x3 && x1 <= x4) || (x2 >= x3 && x2 <= x4)) {
            // cout << "a" << endl;
            if (y4 <= y1) {
                curr_min = curr_min < abs(y4 - y1)*8 ? curr_min : abs(y4 - y1)*8; // Manjse zemljisce je spodaj
                // cout << "1" << endl;
            }
            else if (y3 >= y2) {
                curr_min = curr_min < abs(y2 - y3)*8 ? curr_min : abs(y2 - y3)*8; // Manjse zemljisce je zgoraj  
                // cout << "2" << endl;
            }
        }
        else if ((x4 >= x1 && x4 <= x3) || (x3 >= x1 && x3 <= x2)) {
            // cout << "b" << endl;
            if (y4 <= y1) {
                curr_min = curr_min < abs(y4 - y1)*8 ? curr_min : abs(y4 - y1)*8; // Manjse zemljisce je spodaj
                // cout << "3" << endl;
            }
            else if (y3 >= y2) {
                curr_min = curr_min < abs(y2 - y3)*8 ? curr_min : abs(y2 - y3)*8; // Manjse zemljisce je zgoraj 
                // cout << "4" << endl; 
            }
        }

        // Iscemo razdalje, ce sta zemljisci v skupnem pasu
        else if ((y1 >= y3 && y1 <= y4) || (y2 >= y3 && y2 <= y4)) {
            // cout << "c" << endl;
            if (x4 <= x1) {
                curr_min = curr_min < abs(x4 - x1)*8 ? curr_min : abs(x4 - x1)*8; // Manjse zemljisce je spodaj
                // cout << "5" << endl;
            }
            else if (x3 >= x2) {
                curr_min = curr_min < abs(x2 - x3)*8 ? curr_min : abs(x2 - x3)*8; // Manjse zemljisce je zgoraj  
                // cout << "6" << endl;
            }
        }
        else if ((y4 >= y1 && y4 <= y2) || (y3 >= y1 && y3 <= y2)) {
            // cout << "d" << endl;
            if (x4 <= x1) {
                curr_min = curr_min < abs(x4 - x1)*8 ? curr_min : abs(x4 - x1)*8; // Manjse zemljisce je spodaj
                // cout << "7" << endl;
            }
            else if (x3 >= x2) {
                curr_min = curr_min < abs(x3 - x1)*8 ? curr_min : abs(x3 - x2)*8; // Manjse zemljisce je zgoraj  
                // cout << "8" << endl;
            }
        }

        if (x1 >= x4 && y1 >= y4) { // Levo spodaj
            // cout << "Levo spodaj" << endl;
            curr_min = curr_min < ((sqrt((x1 - x4)*(x1 - x4) + (y1 - y4)*(y1 - y4)))*8) ? 
                       curr_min : ((sqrt((x1 - x4)*(x1 - x4) + (y1 - y4)*(y1 - y4)))*8);
        } 
        else if (x2 <= x3 && y1 >= y4) { // Desno spodaj
            // cout << "Desno spodaj" << endl;
            curr_min = curr_min < ((sqrt((x3 - x2)*(x3 - x2) + (y1 - y4)*(y1 - y4)))*8) ? 
                       curr_min : ((sqrt((x3 - x2)*(x3 - x2) + (y1 - y4)*(y1 - y4)))*8);

        }
        else if (x3 >= x2 && y3 >= y2) { // Desno zgoraj
            // cout << "Desno zgoraj" << endl;
            curr_min = curr_min < ((sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)))*8) ? 
                       curr_min : ((sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)))*8);
        }
        else if (x1 >= x4 && y4 >= y2) { // Levo zgoraj
            // cout << "Levo zgoraj" << endl;
            curr_min = curr_min < ((sqrt((x1 - x4)*(x1 - x4) + (y3 - y2)*(y3 - y2)))*8) ? 
                       curr_min : ((sqrt((x1 - x4)*(x1 - x4) + (y3 - y2)*(y3 - y2)))*8);
        }

        // Output minimum distance
        cout << ceil(curr_min) << "\n";
    }

    return 0;
}
/* 
        // Pas po x-osi
        // Spodnji rob manjsega zemljisca znotraj pasu vecjega zemljisca
        if (y3 >= y1 && y3 <= y2) {
            if (x3 >= x2) {
                curr_min = curr_min < abs(x3 - x2)*8 ? curr_min : abs(x3 - x2)*8; // Manjse zemljisce je desno
            }
            if (x4 <= x1) {
                curr_min = curr_min < abs(x1 - x4)*8 ? curr_min : abs(x1 - x4)*8; // Manjse zemljisce je levo
            }
        }
        // Zgornji rob manjsega zemljisca znotraj pasu vecjega zemljisca
        if (y4 >= y1 && y4 <= y2) {
            if (x3 >= x2) {
                curr_min = curr_min < abs(x3 - x2)*8 ? curr_min : abs(x3 - x2)*8; // Manjse zemljisce je desno
            }
            if (x4 <= x1) {
                curr_min = curr_min < abs(x1 - x4)*8 ? curr_min : abs(x1 - x4)*8; // Manjse zemljisce je levo
            }
        }
        if (x3 >= x1 && x3 <= x2) {
            if (y4 <= y1) { 
                curr_min = curr_min < abs(y4 - y1)*8 ? curr_min : abs(y4 - y1)*8; // Manjse zemljisce je spodaj
            }
            if (y3 >= y2) {
                curr_min = curr_min < abs(y2 - y3)*8 ? curr_min : abs(y2 - y3)*8; // Manjse zemljisce je zgoraj  
            }           
        }
        // Desni rob manjsega zemljisca znotraj pasu vecjega zemljisca
        if (x4 >= x1 && x4 <= x2) {
            if (y4 <= y1) {
                curr_min = curr_min < abs(y4 - y1)*8 ? curr_min : abs(y4 - y1)*8; // Manjse zemljisce je spodaj
            }
            if (y3 >= y2) {
                curr_min = curr_min < abs(y2 - y3)*8 ? curr_min : abs(y2 - y3)*8; // Manjse zemljisce je zgoraj  
            }
        }
        // Menjava spremenljivk
        // Pas po x-osi
        // Spodnji rob manjsega zemljisca znotraj pasu vecjega zemljisca
        if (y1 >= y3 && y1 <= y4) {
            if (x3 >= x2) {
                curr_min = curr_min < abs(x3 - x2)*8 ? curr_min : abs(x3 - x2)*8; // Manjse zemljisce je levo
            }
            if (x4 <= x1) {
                curr_min = curr_min < abs(x1 - x4)*8 ? curr_min : abs(x1 - x4)*8; // Manjse zemljisce je desno
            }
        }
        // Zgornji rob manjsega zemljisca znotraj pasu vecjega zemljisca
        if (y2 >= y3 && y2 <= y4) {
            if (x3 >= x2) {
                curr_min = curr_min < abs(x3 - x2)*8 ? curr_min : abs(x3 - x2)*8; // Manjse zemljisce je levo
            }
            if (x4 <= x1) {
                curr_min = curr_min < abs(x1 - x4)*8 ? curr_min : abs(x1 - x4)*8; // Manjse zemljisce je desno
            }
        }
        // Pas po y-osi
        // Levi rob manjsega zemljisca znotraj pasu vecjega zemljisca
        if (x1 >= x3 && x1 <= x4) {
            if (y4 <= y1) {
                curr_min = curr_min < abs(y4 - y1)*8 ? curr_min : abs(y4 - y1)*8; // Manjse zemljisce je spodaj
            }
            if (y3 >= y2) {
                curr_min = curr_min < abs(y2 - y3)*8 ? curr_min : abs(y2 - y3)*8; // Manjse zemljisce je zgoraj  
            }           
        }
        // Desni rob manjsega zemljisca znotraj pasu vecjega zemljisca
        if (x2 >= x3 && x2 <= x4) {
            if (y4 <= y1) {
                curr_min = curr_min < abs(y4 - y1)*8 ? curr_min : abs(y4 - y1)*8; // Manjse zemljisce je spodaj
            }
            if (y3 >= y2) {
                curr_min = curr_min < abs(y2 - y3)*8 ? curr_min : abs(y2 - y3)*8; // Manjse zemljisce je zgoraj  
            }
        }
        
        // Ce nista v istih pasovih (ni prekrivanja) -> pitagorov izrek
        // Zemljisce ena v sredini in zemljisce dve okoli
        curr_min = curr_min < ((sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)))*8) ? 
                   curr_min : ((sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)))*8); // Desno zgoraj

        curr_min = curr_min < ((sqrt((x3 - x2)*(x3 - x2) + (y1 - y4)*(y1 - y4)))*8) ?
                   curr_min : ((sqrt((x3 - x2)*(x3 - x2) + (y1 - y4)*(y1 - y4)))*8); // Desno spodaj

        curr_min = curr_min < ((sqrt((x1 - x4)*(x1 - x4) + (y3 - y2)*(y3 - y2)))*8) ?
                   curr_min : ((sqrt((x1 - x4)*(x1 - x4) + (y3 - y2)*(y3 - y2)))*8); // Levo zgoraj

        curr_min = curr_min < ((sqrt((x1 - x4)*(x1 - x4) + (y1 - y4)*(y1 - y4)))*8) ?
                   curr_min : ((sqrt((x1 - x4)*(x1 - x4) + (y1 - y4)*(y1 - y4)))*8); // Levo spodaj

        // Zemljisce dve v sredini in zemljisce ena okoli
        curr_min = curr_min < ((sqrt((x1 - x4)*(x1 - x4) + (y1 - y4)*(y1 - y4)))*8) ? 
                   curr_min : ((sqrt((x1 - x4)*(x1 - x4) + (y1 - y4)*(y1 - y4)))*8); // Desno zgoraj

        curr_min = curr_min < ((sqrt((x1 - x4)*(x1 - x4) + (y3 - y2)*(y3 - y2)))*8) ?
                   curr_min : ((sqrt((x1 - x4)*(x1 - x4) + (y3 - y2)*(y3 - y2)))*8); // Desno spodaj

        curr_min = curr_min < ((sqrt((x3 - x2)*(x3 - x2) + (y1 - y4)*(y1 - y4)))*8) ?
                   curr_min : ((sqrt((x3 - x2)*(x3 - x2) + (y1 - y4)*(y1 - y4)))*8); // Levo zgoraj

        curr_min = curr_min < ((sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)))*8) ?
                   curr_min : ((sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)))*8); // Levo spodaj
*/