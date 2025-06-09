#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

bool isCircular(Node *head){
    Node *temp = head;
    
    while(temp->next && temp->next != head){
        temp = temp->next;
    }

    if(temp->next == NULL){
        return 0;
    }else{
        return 1;
    }
}

int main(){
    // create head node
    Node *head = new Node;
    head->data = 3;

    // create second node
    Node *first = new Node;
    first->data = 4;
    head->next = first;

    // create third node
    Node *second = new Node;
    second->data = 5;
    first->next = second;

    // create fourth node
    Node *third = new Node;
    third->data = 6;
    second->next = third;
    third->next = head;

    // is linked list circular or not
    cout << isCircular(head);
    
    return 0;
}