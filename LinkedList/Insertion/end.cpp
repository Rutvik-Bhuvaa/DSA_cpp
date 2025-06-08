#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

int main(){
    // create head node
    Node *head = new Node;
    head->data = 1;
    Node *temp = head;

    // create second node
    Node *second = new Node;
    second->data = 2;
    head->next = second;

    // create third node
    Node *third = new Node;
    third->data = 3;
    second->next = third;

    // create fourth node
    Node *fourth = new Node;
    fourth->data = 4;
    third->next = fourth;

    // Insert node at the end of the LinkedList
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new Node;
    temp = temp->next;
    temp->data = 5;

    // Print the linked list
    Node *iter = head;
    while(iter != NULL){
        cout << iter->data << " ";
        iter = iter->next;
    }
    return 0;
}