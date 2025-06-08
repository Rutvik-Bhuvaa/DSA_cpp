#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

int main(){
    // Create head node
    Node *head = new Node;
    head->data = 3;

    // Create second node
    Node *second = new Node;
    second->data = 6;
    head->next = second;

    // Create third node
    Node *third = new Node;
    third->data = 9;
    second->next = third;
    third->next = NULL;

    // Insertion from start
    Node *temp = new Node;
    temp->data = 1;
    temp->next = head;
    head = temp;

    // Print the list
    Node* iterator = head;
    while(iterator != NULL) {
        cout << iterator->data << " -> ";
        iterator = iterator->next;
    }
    cout << "NULL" << endl;

    return 0;
}