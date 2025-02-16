#include <iostream>
using namespace std;

void transpose(int arr[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(arr[i][j], arr[j][i]);  
        }
    }
}

void flipVertically(int arr[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n /2; j++) {
            swap(arr[i][j], arr[i][n-j-1]);
        }
    }
}

void printMatrix(int arr[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 3;
    int arr[3][3];

    cout << "Enter the matrix elements: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    transpose(arr, n);

    flipVertically(arr, n);

    cout << "Matrix after 90-degree clockwise rotation: " << endl;
    printMatrix(arr, n);

    return 0;
}
