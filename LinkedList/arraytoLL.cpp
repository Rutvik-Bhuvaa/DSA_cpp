#include<iostream>
using namespace std;


class Node{
    public:
    int data; 
    Node *next;
};

void print(Node *iter){
    cout << "Printing the Linked List: " << endl;
    while(iter != NULL){
        cout << iter->data << " ";
        iter = iter->next;
    }
    cout << endl;

}

void printReverse(Node *iter){
    if(iter == NULL){
        return;
    }

    printReverse(iter->next);
    cout << iter->data << " ";
}

int main(){
    int n;
    cout << "Enter the size of an array: " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter the values in the array: " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // creating LL from an array
    Node *head = new Node;
    head->data = arr[0];
    Node *temp = head;

    for(int i=1; i<n; i++){
        temp->next = new Node;
        temp = temp->next;
        temp->data = arr[i];
    }
    temp->next = NULL; 

    Node *iter = head;

    print(iter);
    cout << "Reverse: ";
    printReverse(iter);
    cout << endl;
    return 0;
}