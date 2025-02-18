// Given two strings denoting non-negative numbers s1 and s2. Calculate the sum of s1 and s2. 

#include<iostream>
#include<algorithm>
using namespace std;

string findSum(string s1, string s2){
    string str = "";
    int i = s1.size()-1;
    int j = s2.size()-1;
    int numOne, numTwo, bit, carry = 0;
    char ch;

    while(i>=0 && j>=0){
        numOne = s1[i] - '0';
        numTwo = s2[i] - '0';
        
        numOne += numTwo + carry;

        carry = numOne/10;
        bit = numOne%10;

        ch = '0' + bit;
        str += ch;
        i--;
        j--;
    }

    while(i>=0){
        numOne = s1[i] - '0' + carry;

        carry = numOne/10;
        bit = numOne%10;

        ch = '0' + bit;
        str += ch;
        i--;
    }

    while(j >= 0){
        numTwo = s2[j] - '0' + carry;

        carry = numTwo/10;
        bit = numTwo%10;

        ch = '0' + bit;
        str += ch;
        j--;
    }

    if(carry){
        str += '0' + carry;
    }

    int k = str.size()-1;
    while(k>0 && str[i] == '0'){
        str.pop_back();
        k--;
    }
    reverse(str.begin(), str.end());
    return str;
}

int main(){
    string str1;
    cout << "Enter the 1st string: " ;
    cin >> str1;

    string str2;
    cout << "Enter the 3nd string: ";
    cin >> str2;

    string result = findSum(str1, str2);
    cout << "Total sum is: " << result;
    return 0;
}