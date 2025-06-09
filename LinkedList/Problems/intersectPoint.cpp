//Problem: Given the head of two singly linked lists, return the point where these two linked lists intersect.

// Note: It is guaranteed that the intersected node always exists.

// Custom Input Format:

// head1 contains the nodes before intersection in list1
// head2 contains the nodes before intersection in list2
// CommonList contains the nodes after intersection of list1 and list2.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

// Function to get length
int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Intersection finder
Node* getIntersectionNode(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int diff = abs(len1 - len2);

    Node* a = head1;
    Node* b = head2;

    if (len1 > len2)
        while (diff--) a = a->next;
    else
        while (diff--) b = b->next;

    while (a && b) {
        if (a == b) return a;
        a = a->next;
        b = b->next;
    }
    return NULL;
}

int main() {
    // Common List: 4 -> 4
    Node* common = new Node(4);
    common->next = new Node(4);

    // head1: 4 -> 4 -> 4 -> [4 -> 4]
    Node* head1 = new Node(4);
    head1->next = new Node(4);
    head1->next->next = new Node(4);
    head1->next->next->next = common;

    // head2: 4 -> [4 -> 4]
    Node* head2 = new Node(4);
    head2->next = common;

    Node* result = getIntersectionNode(head1, head2);
    if (result)
        cout << "Intersection at: " << result->data << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}
