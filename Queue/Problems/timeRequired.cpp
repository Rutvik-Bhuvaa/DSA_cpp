// Problem : 2073. Time Needed to Buy Tickets
// There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

// You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

// Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

// Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int total = tickets[k];

        // Before position k (from 0 to k-1)
        for (int i = 0; i < k; i++) {
            total += min(tickets[i], tickets[k]);
        }

        // After position k (from k+1 to n-1)
        for (int i = k + 1; i < n; i++) {
            total += min(tickets[i], tickets[k] - 1);
        }

        return total;
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> tickets = {2, 3, 2};
    int k = 2;

    int result = sol.timeRequiredToBuy(tickets, k);
    cout << "Time required for person at position " << k << " to buy all tickets: " << result << " seconds" << endl;

    return 0;
}
