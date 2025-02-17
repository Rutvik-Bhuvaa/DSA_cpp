// Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

#include<iostream>
using namespace std;

 string toLowerCase(string s) {
        
        for(int i=0; i<s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = s[i] + ('a' - 'A');
            }
        }
        return s;

    }

int main(){
    string str; 
    cout << "Enter the string: ";
    cin >> str;

    string ans = toLowerCase(str);
    cout << "String in lower case is: " << ans;
    return 0;
}