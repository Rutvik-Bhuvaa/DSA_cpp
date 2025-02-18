// Given a string s, find the length of the longest substring without repeating characters. 

#include<iostream>
using  namespace std;

int longestUniqueSubstring(string str){

    bool count[26] = {0};
    int first = 0;
    int second = 1;
    int totalLength = 1;

    count[str[first] - 'a'] = 1;

    while(second < str.size()){
        while(count[str[second] - 'a']){
            count[str[first] - 'a'] = 0;
            first++;
        }
        count[str[second] - 'a'] = 1;
        totalLength = max(totalLength, second-first+1);
        second++;
    }

    return totalLength;
}

int main(){
    string str;
    cout << "Enter the string: ";
    cin >> str;

    int length = longestUniqueSubstring(str);
    cout << "Longest unique substring length is " << length;
    return 0;
}