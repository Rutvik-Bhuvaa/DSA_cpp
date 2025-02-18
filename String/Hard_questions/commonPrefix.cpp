#include <iostream>
#include <vector>
#include <climits>
using namespace std;

string longestCommonPrefix(vector<string> str) {
    if (str.empty()) {
        return "";
    }

    int minLength = INT_MAX;
    for (int i = 0; i < str.size(); i++) {
        minLength = min(minLength, (int)str[i].size()); 
    }

    string prefix = "";
    for (int i = 0; i < minLength; i++) {
        char ch = str[0][i]; 
        for (int j = 1; j < str.size(); j++) { 
            if (str[j][i] != ch) {
                return prefix;
            }
        }
        prefix += ch;
    }
    return prefix;
}

int main() {
    vector<string> str = {"geeksforgeeks", "geeks", "geek", "geezer"};

    string result = longestCommonPrefix(str);
    cout << "Longest common prefix is: " << result << endl;

    return 0;
}
