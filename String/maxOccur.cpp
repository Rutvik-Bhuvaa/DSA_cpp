// Given a string s of lowercase alphabets. The task is to find the maximum occurring character in the string s. If more than one character occurs the maximum number of times then print the lexicographically smaller character

#include<iostream>
using namespace std;

char getMaximumOccuringChar(string str){
    int count[26] = {0};

    for(int i=0; i<str.size(); i++){
        int index = str[i] - 'a';
        count[index]++;
    }

    int maxElement = 0;

    for(int i=0; i<26; i++){
        if(count[i] > count[maxElement]){
            maxElement = i;
        }
    }

    return 'a' + maxElement;
}

int main(){
    string str;
    cout << "Enter the string: ";
    cin >> str;

    char maxOccur = getMaximumOccuringChar(str);
    cout << "Maximum occuring character is: " << maxOccur;
    return 0;
}