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

    // Create fourth node
    Node *fourth = new Node;
    fourth->data = 12;
    third->next = fourth;

    // Insert node in between 
    Node *temp = head;
    while(temp->data != 6){
        temp = temp->next;
    }

    Node *rnd = new Node;
    rnd->data = 8;
    rnd->next = temp->next;
    temp->next = rnd;

    // Print the list
    Node* iter = head;
    while(iter != NULL) {
        cout << iter->data << " -> ";
        iter = iter->next;
    }
    cout << "NULL" << endl;

    return 0;
}