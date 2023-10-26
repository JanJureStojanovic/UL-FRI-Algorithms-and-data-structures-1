#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    // Stack and Queue data structures
    stack<pair<int, int>> sklad;
    stack<pair<int, int>> vrsta;

    // Add the first element to the stack and queue
    int num;
    cin >> num;

    sklad.push(make_pair(0, num));
    vrsta.push(make_pair(0, num));

    long long final_sum = 0;
    int queue_max = num;

    pair<int, int> new_pair;

    // For loop over all n inputs
    for (int i = 1; i < n; i++) {

        // Scan the new number and create a new pair using the index i
        cin >> num;
        new_pair = make_pair(i, num);

        // --------------- STACK_1 OPERATIONS ---------------

        // Pop stack while stack top is smaller than the i-th element
		while (sklad.empty() == false && sklad.top().second < num) {
            final_sum += i - sklad.top().first - 1;
			sklad.pop();
		}

		// Push next element to stack (We found all smaller than the current i-th element)
		sklad.push(new_pair);

        // --------------- STACK_2 OPERATIONS ---------------

        /* If the new number is bigger than the current max element of queue, we add its index
        to the final sum and empty the stack and add the new element and its index as only stack
        element and change the current max*/

        if (num >= queue_max) {

            if (num > queue_max) { 

                final_sum += i; // We can see all towers before the current one
                queue_max = num; // Set new max

                // Empty queue
                while (vrsta.empty() == false) {
                    vrsta.pop();
                }

            } else {
                final_sum += i;
            }
            // Add the new max element as only pair
            vrsta.push(new_pair);
            continue;
        }

        if (num < vrsta.top().second) {

            // We simply add the new pair and continue
            vrsta.push(new_pair);
            continue;

        } 
        
        if (num >= vrsta.top().second) { 
            
            // We empty all elements we can see over
            while (num >= vrsta.top().second) {
                vrsta.pop();
            }

            // Primerjamo indekse
            final_sum += i - vrsta.top().first - 1;
            // Add the new element (if we can see over this one we can se over all of the ones before it)
            vrsta.push(new_pair);
        }
	}

    // --------------- STACK_1 OPERATIONS ---------------

    // Stack filled with el. with no greater elements
	while (sklad.empty() == false) {
		final_sum += n - sklad.top().first - 1;
		sklad.pop();
	}

    cout << final_sum << endl;
    
}
