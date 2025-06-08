#include<iostream>
using namespace std;

// Creation of LinkedList
class Node{
    public:
    int data;
    Node *next;
}

int main(){
    Node *head = new Node;
    head->data = 36;
    head->next = new Node;
    first = head;
    first = first->next;
    first->data = 28;
    first->next = new Node;
    first = first->next;
    first->data = 4;
    first->next = new Node;
    first = first->next;
    first->data = 9;
    return 0;
}