#include<iostream>
using namespace std;

// Creation of LinkedList
class Node{
    public:
    int data;
    Node *next;
};

int main(){
     // Create head node
     Node* head = new Node;
     head->data = 36;
 
     // Create second node
     Node* second = new Node;
     second->data = 28;
     head->next = second;
 
     // Create third node
     Node* third = new Node;
     third->data = 4;
     second->next = third;
 
     // Create fourth node
     Node* fourth = new Node;
     fourth->data = 9;
     third->next = fourth;

    // Print the list
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return 0;
}