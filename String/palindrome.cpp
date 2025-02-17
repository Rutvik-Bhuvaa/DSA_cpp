#include<iostream>
using namespace std;


bool isPalindrome(string str){
    int first = 0;
    int last = str.size()-1;

    while(first < last){
        if(str[first] != str[last]){
            return 0;
        }
        first++;
        last--;
    }
    return 1;
}

int main(){
    string str;
    cout << "Enter the string: ";
    cin >> str;

    int result = isPalindrome(str);

    if(result){
        cout << "PALINDROME";
    }else{
        cout << "NOT PALINDROME";
    }
    return 0;
}