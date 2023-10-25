#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void printNGE(int arr[], int n) { 

	stack<int> s;

	// Push the first element to stack */
	s.push(0);

	// Iterate for rest of the elements
	for (int i = 1; i < n; i++) {

		if (s.empty()) {
			s.push(i);
			continue;
		}

        // Pop stack while stack top is smaller than the i-th element
		while (s.empty() == false && arr[s.top()] < arr[i]) {
			cout << s.top() << " --> " << i << endl;
			s.pop();
		}

		// Push next element to stack (We found all smaller than the current i-th element)
		s.push(i);
	}

	// Stack filled with el. with no greater elements
	while (s.empty() == false) {
		cout << s.top() << " --> " << -1 << endl;
		s.pop();
	}
}

int main() {

    int n;

    // Stack and Queue data structures
    stack<pair<int, int>> sklad;
    vector<pair<int, int>> vrsta;

    // Add the first element to the stack and queue
    int num;
    cin >> num;

    sklad.push(make_pair(0, num));
    vrsta.push_back(make_pair(0, num));

    int final_sum = 0;

    pair<int, int> new_pair;

    // For loop over all n inputs
    for (int i = 1; i < n; i++) {

        // Scan the new number and create a new pair using the index i
        cin >> num;
        new_pair = make_pair(i, num);

        // If our stack is empty we add a new pair and continue
        if (sklad.empty()) {
			sklad.push(new_pair);
			continue;
		}

        // Pop stack while stack top is smaller than the i-th element
		while (sklad.empty() == false && sklad.top().second < num) {
            final_sum += i - sklad.top().first - 1;
			sklad.pop();
		}

		// Push next element to stack (We found all smaller than the current i-th element)
		sklad.push(new_pair);
	}

    // Stack filled with el. with no greater elements
	while (sklad.empty() == false) {
		final_sum += n - sklad.top().first - 1;
		sklad.pop();
	}

    cout << final_sum << endl;
    
}
