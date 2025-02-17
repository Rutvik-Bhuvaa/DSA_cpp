// Given two strings s1 and s2 in lowercase, the task is to make them anagrams. The only allowed operation is to remove a character from any string. Find the minimum number of characters to be deleted to make both the strings anagram. Two strings are called anagrams of each other if one of them can be converted into another by rearranging its letters.

#include<iostream>
using namespace std;

int remAnagram(string strOne, string strTwo){
    int count[26] = {0};

    for(int i=0; i<strOne.size(); i++){
        count[strOne[i] - 'a']++;
    }

    for(int i=0; i<strTwo.size(); i++){
        count[strTwo[i] - 'a']--;
    }

    int deletions = 0;

    for(int i=0; i<26; i++){
        deletions += abs(count[i]);
    }

    return deletions;
}

int main(){
    string strOne;
    string strTwo;
    cout << "Enter the 1st string: ";
    cin >> strOne;
    cout << "Enter the 2nd string: ";
    cin >> strTwo;

    int result = remAnagram(strOne, strTwo);
    cout << "Total removed character is: " << result;
    return 0;
}