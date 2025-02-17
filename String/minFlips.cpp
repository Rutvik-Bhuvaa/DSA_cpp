// Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.

#include<iostream>
using namespace std;

int minFlips(string s){
    int countOne = 0;
    int countTwo = 0;
    int flag = 0;
    for(int i=0; i<s.size(); i++){
        if(flag != s[i]-'0'){
            countOne++;
        }
        flag = !flag;
    }
    flag = 1;
    for(int i=0; i<s.size(); i++){
        if(flag != s[i]-'0'){
            countTwo++;
        }
        flag = !flag;
    }
    return min(countOne, countTwo);
}

int main(){
    string str;
    cout << "Enter the binary string: ";
    cin >> str;

    int ans = minFlips(str);
    cout << "Minimum flips: " << ans;
    return 0;
}