// Given a binary string S. The task is to count the number of substrings that start and end with 1. For example, if the input string is “00100101”, then there are three substrings “1001”, “100101” and “101”.

#include<iostream>
using namespace std;

long binarySubstring(string str){
    if(str.size() < 2){
        return 0;
    }

    long count = 0;

    for(int i=0; i<str.size(); i++){
        if(str[i] == '1'){
            count++;
        }
    }
    count = count*(count-1);
    count /= 2;

    return count;
}

int main(){
    string str;
    cout << "Enter the binary string: ";
    cin >> str;

    long result = binarySubstring(str);
    cout << "Total possible sub-string is: " << result;
    return 0;

}