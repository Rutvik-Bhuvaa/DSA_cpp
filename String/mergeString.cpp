// Given two strings S1 and S2 as input, the task is to merge them alternatively i.e. the first character of S1 then the first character of S2 and so on till the strings end.
// NOTE: Add the whole string if other string is empty.

#include<iostream>
using namespace std;

string mergeString (string s1, string s2)
{
    // your code here
    string merged;
    int i=0, j=0;
    
    while(i < s1.size() && j < s2.size()){
        merged += s1[i];
        merged += s2[j];
        i++;
        j++;
    }
    
    while(i < s1.size()){
        merged += s1[i];
        i++;
    }
    
    while(j < s2.size()){
        merged += s2[j];
        j++;
    }
    
    return merged;
}

int main(){
    string strOne;
    string strTwo;
    cout << "Enter the 1st string: ";
    cin >> strOne;
    cout << "Enter the 2nd string: ";
    cin >> strTwo;

    string result = mergeString(strOne, strTwo);
    cout << "Merged string is: " << result;
    return 0;
}