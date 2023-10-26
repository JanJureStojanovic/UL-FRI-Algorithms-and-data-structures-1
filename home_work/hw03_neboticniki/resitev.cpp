#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void PrintStack(stack<int> s)
{
    // If stack is empty then return
    if (s.empty()) 
        return;
     
 
    int x = s.top();
 
    // Pop the top element of the stack
    s.pop();
 
    // Recursively call the function PrintStack
    PrintStack(s);
 
    // Print the stack element starting
    // from the bottom
    cout << x << " ";
 
    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}

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

    int front_sum = 0;
    int back_sum = 0;
    int queue_max = -1;

    pair<int, int> new_pair;

    // For loop over all n inputs
    for (int i = 1; i < n; i++) {

        PrintStack(sklad);
        cout << endl;
        PrintStack(vrsta);
        cout << endl;
        cout << endl;

        // Scan the new number and create a new pair using the index i
        cin >> num;
        new_pair = make_pair(i, num);

        // --------------- STACK OPERATIONS ---------------

        // Pop stack while stack top is smaller than the i-th element
		while (sklad.empty() == false && sklad.top().second < num) {
            front_sum += i - sklad.top().first - 1;
			sklad.pop();
		}

		// Push next element to stack (We found all smaller than the current i-th element)
		sklad.push(new_pair);

        // --------------- QUEUE OPERATIONS  --------------

        /* If the new number is bigger than the current max element of queue, we add its index
        to the final sum and empty the stack and add the new element and its index as only stack
        element and change the current max*/

        if (num > queue_max) {

            back_sum += i; // We can see all towers before the current one
            queue_max = num; // Set new max

            // Empty queue
            while (vrsta.empty() == false) {
                vrsta.pop();
            }
            // Add the new max element as only pair
            vrsta.push(new_pair);
            continue;
        }

        if (num < vrsta.top().second) {

            // We simply add the new pair and continue
            vrsta.push(new_pair);
            continue;

        } else {

            while (num >= vrsta.top().second) {
                vrsta.pop();
            }

            // Primerjamo indekse
            back_sum += i - vrsta.top().first - 1;

            vrsta.push(new_pair);

        }
	}

    // --------------- STACK OPERATIONS ---------------

    // Stack filled with el. with no greater elements
	while (sklad.empty() == false) {
		front_sum += n - sklad.top().first - 1;
		sklad.pop();
	}

    cout << front_sum << endl;
    cout << back_sum << endl;
    
}
