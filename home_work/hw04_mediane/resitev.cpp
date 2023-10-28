#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
 
int main() {

    int n;
    cin >> n;

    // Za izpis najvecjega elementa v spodnji polovici
    priority_queue<int> bottom_half;

    // Za izpis najmanjsega elementa v zgornji polovici
    priority_queue <int, vector<int>, greater<int>> top_half;

    // Meant for scanning new elements
    int num;

    for (int i = 0; i < n; i++) {

        cin >> num;

        /*
        Find the appropriate priority_queue for the current element:
        Check if the element is smaller than the top element of the bottom_half.
        If it is, add it to the bottom_half priority_queue. Also, add it if the bottom_half
        priority_queue is empty.
        */
        if (bottom_half.empty() || num < bottom_half.top()) {
            bottom_half.push(num);
        } else {
            top_half.push(num);
        }

        /* 
        Ensure that the sizes of the priority_queues are the same or differ by at most one element.
        We do so by moving the top element of either queue into the other when one is larger by more
        than one element
        */
        if (bottom_half.size() > top_half.size() + 1) {
            top_half.push(bottom_half.top());
            bottom_half.pop();
        } else if (top_half.size() > bottom_half.size()) {
            bottom_half.push(top_half.top());
            top_half.pop();
        }

        // Output the median value
        if (bottom_half.size() >= top_half.size()) {
            cout << bottom_half.top() << "\n";
        } else  {
            cout << top_half.top() << "\n";
        }
    }
}