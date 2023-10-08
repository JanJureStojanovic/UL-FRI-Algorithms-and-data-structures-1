#include <iostream>
#include <string>
#include <algorithm>

int main() {

    // Our straight length and number of lamps
    int m, n;
    std::cin >> m >> n;

    // Our straight (0 = no light, 7 = light)
    int arr[m] = {0};

    /* 
    // Array of pairs holding the location of all lamps and their corresponding lengths
    std::pair<int, int> pairs[n];
    
    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        pairs[i] = std::make_pair(l, r);
    }
    */
    
    for (int i = 0; i < n; i++) {
        
        // Lamp location and length 
        int a, b;
        std::cin >> a >> b;

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
        //std::cout << arr[i] << " ";
        if (arr[i] != 7) sum++;
    }
    //std::cout << std::sendl;
    std::cout << sum << std::endl;
}