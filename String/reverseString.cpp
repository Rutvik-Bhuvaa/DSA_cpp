
#include<iostream>
using namespace std;

void reverse(string str){
    int first = 0;
    int last = str.size() -1;

    while(first < last){
        swap(str[first], str[last]);
        first++;
        last--;
    }

    for(int i=0; i<str.size(); i++){
        cout << str[i];
    }
}

int main(){
    string str; 
    cout << "Enter the string you want to reverse: ";
    cin >> str;

    reverse(str);
    

    return 0;
}