// Search in a 2D matrix
// conditions: 
// i) Integers in each row are sorted in ascending from left to right.
// ii) Integers in each column are sorted in ascending from top to bottom.

#include<iostream> 
using namespace std;

bool searchElement(int arr[][5], int row, int col, int key){
    int first = row-1;
    int second = 0;
    
    while(first >= 0 && second < col){
        if(arr[first][second] == key){
            return 1;
        }else if(arr[first][second] < key){
            second++;
        }else{
            first--;
        }
    }
    return 0;
}

int main(){
    int row = 5;
    int col = 5;

    int arr[5][5];
    cout << "Enter the no: " << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
        }
    }

    int key;
    cout << "Enter the element you want to find: ";
    cin >> key;

    int result = searchElement(arr, row, col, key);
    if(result){
        cout << "Element is present";
    }else{
        cout << "Element is not present";
    }
}