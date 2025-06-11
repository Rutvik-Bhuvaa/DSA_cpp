// Problem: Clone List with Next and Random
// You are given a special linked list with n nodes where each node has two pointers a next pointer that points to the next node of the singly linked list, and a random pointer that points to the random node of the linked list.

// Construct a copy of this linked list. The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list, such that it also represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// Return the head of the copied linked list.

// NOTE : Original linked list should remain unchanged.

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *random;
    Node(int val){
        data = val;
        next = nullptr;
        random = nullptr;
    }
};

Node *clonedLinkedList(Node *head){
    Node *clone = head;
    while(clone){
        Node *temp = new Node(clone->data);
        temp->next = clone->next;
        clone->next = temp;
        clone = clone->next->next;
    }

    clone = head;

    while(clone){
        if(clone->random)
        clone->next->random = clone->random->next;
        clone = clone->next->next;
    }

    Node *first = head;
    Node *copy = head->next;
    Node *clonedHead = copy;

    while(first){
        first->next = copy->next;
        if(first->next)
        copy->next = first->next->next;
        first = first->next;
        copy = copy->next;
    }

    return clonedHead;

}

void printList(Node *head){
    Node *temp = head;
    while(temp){
        cout << temp->data;
        if(temp->next){
            cout << "->";
        }
        temp = temp->next;
    }
}


int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Set random pointers
    head->random = head->next->next;             // 1 -> 3
    head->next->random = head;                   // 2 -> 1
    head->next->next->random = head->next->next; // 3 -> 3
    head->next->next->next->random = head->next; // 4 -> 2

    cout << "Original list: " << endl;
    printList(head);

    Node *cloned = clonedLinkedList(head);

    cout << "\nCloned list:\n";
    printList(cloned);
    return 0;
}