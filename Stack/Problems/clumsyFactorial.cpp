// Problem: Clumsy Factorial
// The factorial of a positive integer n is the product of all positive integers less than or equal to n.

// For example, factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.
// We make a clumsy factorial using the integers in decreasing order by swapping out the multiply operations for a fixed rotation of operations with multiply '*', divide '/', add '+', and subtract '-' in this order.

// For example, clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.
// However, these operations are still applied using the usual order of operations of arithmetic. We do all multiplication and division steps before any addition or subtraction steps, and multiplication and division steps are processed left to right.

// Additionally, the division that we use is floor division such that 10 * 9 / 8 = 90 / 8 = 11.

// Given an integer n, return the clumsy factorial of n.

#include <iostream>
#include <stack>
using namespace std;

int clumsy(int n) {
    stack<int> s;
    s.push(n--);

    int i = 0;
    while(n > 0){
        if(i == 0){
            s.top() *= n;  // multiply
        }else if(i == 1){
            s.top() /= n;  // divide
        }else if(i == 2){
            s.push(n);     // add (positive push)
        }else{
            s.push(-n);    // subtract (negative push)
        }
        i = (i + 1) % 4;
        n--;
    }

    int sum = 0;
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }

    return sum;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Clumsy factorial of " << n << " is: " << clumsy(n) << endl;
    return 0;
}
