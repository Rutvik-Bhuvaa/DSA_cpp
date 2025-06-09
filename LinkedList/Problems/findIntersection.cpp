// Problem: Given that two linked lists are sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made without changing the original lists.

// Note: The elements of the linked list are not necessarily distinct.

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
    
        Node(int val) {
            data = val;
            next = NULL;
        }
};

// Function to find intersection of two sorted lists
Node* findIntersection(Node* head1, Node* head2) {
    Node* a = head1;
    Node* b = head2;

    // Dummy node for the result list
    Node* dummy = new Node(0);
    Node* tail = dummy;

    while (a && b) {
        if (a->data == b->data) {
            tail->next = new Node(a->data);
            tail = tail->next;
            a = a->next;
            b = b->next;
        }
        else if (a->data < b->data) {
            a = a->next;
        }
        else {
            b = b->next;
        }
    }

    return dummy->next;
}


void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}



int main(){
    // Linked List 1: 1 -> 2 -> 3 -> 4 -> 6
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(6);

    // Linked List 2: 2 -> 4 -> 6 -> 8
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);

    // Find intersection
    Node* result = findIntersection(head1, head2);

    // Output: 2 -> 4 -> 6
    printList(result);
    return 0;
}