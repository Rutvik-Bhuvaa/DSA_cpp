// Problem: Gas Station
// There are some gas stations along a circular route. You are given two integer arrays gas[] denoted as the amount of gas present at each station and cost[] denoted as the cost of travelling to the next station. You have a car with an unlimited gas tank. You begin the journey with an empty tank from one of the gas stations. Return the index of the starting gas station if it's possible to travel around the circuit without running out of gas at any station in a clockwise direction. If there is no such starting station exists, return -1.
// Note: If a solution exists, it is guaranteed to be unique.

#include <iostream>
#include <vector>
using namespace std;

int startStation(vector<int> &gas, vector<int> &cost) {
    int totalGas = 0, totalCost = 0;
    int remainingGas = 0;
    int front = 0;
    int n = gas.size();

    for (int i = 0; i < n; i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        remainingGas += gas[i] - cost[i];

        if (remainingGas < 0) {
            front = i + 1;
            remainingGas = 0;
        }
    }

    return (totalGas < totalCost) ? -1 : front;
}

int main() {
    // Example input
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int result = startStation(gas, cost);
    if (result != -1) {
        cout << "You can start at station index: " << result << endl;
    } else {
        cout << "It's not possible to complete the circuit." << endl;
    }

    return 0;
}
