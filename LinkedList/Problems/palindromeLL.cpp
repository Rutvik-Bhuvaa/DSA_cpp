//Problem: Palindrome Linked List

// Given a head singly linked list of positive integers. The task is to check if the given linked list is palindrome or not.

// Examples:

// Input: head: 1 -> 2 -> 1 -> 1 -> 2 -> 1
// Output: true
// Explanation: The given linked list is 1 -> 2 -> 1 -> 1 -> 2 -> 1 , which is a palindrome and Hence, the output is true.

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

// Function to insert new node at end of the list
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next; // Move to the end of the list
    }
    temp->next = newNode; // Attach new node at the end
}

// Function to reverse a linked list
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;

    // Reverse the list by changing links
    while (current != NULL) {
        Node* nextNode = current->next; // Save next node
        current->next = prev;           // Reverse the link
        prev = current;                 // Move prev forward
        current = nextNode;             // Move current forward
    }

    return prev; // New head of reversed list
}

bool isPalindrome(Node *head){
    // Step 1: Edge cases
    if (head == NULL || head->next == NULL) {
        return true; // Empty or 1-element list is always palindrome
    }

    // Step 2: Find the middle of the list using slow and fast pointer
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 3: Reverse the second half of the list
    Node* secondHalfStart = reverse(slow->next);

     // Step 4: Compare both halves
     Node* firstHalf = head;
     Node* secondHalf = secondHalfStart;
     while (secondHalf != NULL) {
         if (firstHalf->data != secondHalf->data) {
             return false; // Mismatch found
         }
         firstHalf = firstHalf->next;
         secondHalf = secondHalf->next;
     }
 
     return true; // All elements matched, it's a palindrome
 }


void printList(Node *head){
    Node *temp = head;
    while(temp){
        cout << temp->data;
        if(temp->next) cout << "->";
        temp = temp->next;
    }
}

int main(){

    Node *head = NULL;

    insert(head, 1);
    insert(head, 2);
    insert(head, 1);
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);

    cout << "Linked List: ";
    printList(head);
    cout << endl;

    
    if (isPalindrome(head)) {
        cout << "Output: Palindrome" << endl;
    } else {
        cout << "Output: Not Palindrome" << endl;
    }

    return 0;
}