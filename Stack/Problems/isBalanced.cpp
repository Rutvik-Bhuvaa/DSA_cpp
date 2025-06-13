// Problem: Parenthesis Checker
// Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']', verify the validity of the arrangement.
// An input string is valid if:

//          1. Open brackets must be closed by the same type of brackets.
//          2. Open brackets must be closed in the correct order.

#include<iostream>
#include<stack>
using namespace std;


bool isBalanced(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) return false;

            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return st.empty();
}

int main(){
    string s;
    cout << "Enter the expression: ";
    cin >> s;

    if (isBalanced(s)) {
        cout << "Output: true\n";
        cout << "Explanation: All the brackets are well-formed.\n";
    } else {
        cout << "Output: false\n";
        cout << "Explanation: The expression is not balanced.\n";
    }

    return 0;
}