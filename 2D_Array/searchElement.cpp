// Search in a 2D matrix
// conditions: 
// i) Each row is sorted in non-decreasing order. 
// ii) The first integer of each row is greater than the last integer of the previous row.


#include<iostream> 
using namespace std;

bool searchElement(int arr[][4], int row, int col, int key){
    int start = 0;
    int end = (row*col)-1;
    
    while(start <= end){
        int mid = end + (start-end)/2;
        int rowIndex = mid/col;
        int colIndex = mid%col;

        if(arr[rowIndex][colIndex] == key){
            return true;
        }else if(arr[rowIndex][colIndex] > key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return false;
}

int main(){
    int row = 3;
    int col = 4;

    int arr[3][4];
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