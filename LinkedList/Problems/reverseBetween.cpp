// Problem: Reverse a sublist of a linked list
// Difficulty: HardAccuracy: 62.68%Submissions: 17K+Points: 8
// Given a linked list and positions a and b. Reverse the linked list from position a to b and return the head of the resultant linked list.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Reverse first 'n' nodes from given head
Node* reverseLinkedList(Node* head, int n) {
    Node* prev = nullptr;
    Node* current = head;

    while (n-- && current) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    // head is now the tail of reversed part, connect to remaining
    head->next = current;

    return prev; // new head of reversed segment
}

// Reverse from position a to b
Node* reverseBetween(int a, int b, Node* head) {
    if (!head || a == b) return head;

    int count = 1;
    Node* iter = head;
    Node* beforeStart = nullptr;
    Node* start = nullptr;
    Node* end = nullptr;

    // Step 1: Traverse to identify nodes
    while (count <= b) {
        if (count == a - 1) beforeStart = iter;
        if (count == a) start = iter;
        if (count == b) end = iter;
        iter = iter->next;
        count++;
    }

    // Step 2: Reverse sublist starting from 'start'
    Node* newSubHead = reverseLinkedList(start, b - a + 1);

    // Step 3: Connect the parts
    if (beforeStart) {
        beforeStart->next = newSubHead;
        return head;
    } else {
        return newSubHead; // when a == 1
    }
}

// Utility function to create list
Node* createList(int arr[], int n) {
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Utility to print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createList(arr, size);

    cout << "Original List: ";
    printList(head);

    int a = 2, b = 4;
    head = reverseBetween(a, b, head);

    cout << "List after reversing from position " << a << " to " << b << ": ";
    printList(head);

    return 0;
}
