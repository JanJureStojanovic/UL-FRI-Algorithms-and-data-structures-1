#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;



int main() {

    int n, w;
    cin >> n >> w;

    int arr[n][2];

    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    } 

      
}

/* Uporabi vektor, spomni se funkcije podvajanja iz predavanja (to uporabi za izpis array-a 0, 1 in 2)

void izpisi(vector<int> v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

auto podvoji(vector<int> v) {
    int n=v.size();
    for (int i=0; i<n; i++) {
        v.push_back(v[i]);
    }
    return v;
}

vector<int> a = {1,2,3,4,5};
vector<int> b = podvoji(a);
izpisi(a);
izpisi(b);

Output:
1 2 3 4 5 
1 2 3 4 5 1 2 3 4 5 */

