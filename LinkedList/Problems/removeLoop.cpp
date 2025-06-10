#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
};

void removeLoop(Node* head) {
    // code here
    if(head == head->next){
        head->next = NULL;
        return;
    }

    if(head->next == NULL) {
        return;
    }

    Node *slow = head;
    Node *fast = head;

    fast = head->next->next;
    slow = head->next;

    while(fast && fast->next && fast!=slow){
        fast = fast->next->next;
        slow = slow->next;
    }

    if(!fast || !fast->next){
        return;
    }

    fast = head;

    if(fast == slow){
        while(slow->next != fast){
            slow = slow->next;
        }
        slow->next = NULL;
        return;
    }

    while(fast->next != slow->next){
        fast = fast->next;
        slow = slow->next;
    }

    while(fast->next != slow->next){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;
    return;

}



int main() {
    // Test case 1: Create linked list 1->3->4 with loop at position 2
    Node* head1 = new Node{1, NULL};
    head1->next = new Node{3, NULL};
    head1->next->next = new Node{4, NULL};
    head1->next->next->next = head1->next; // Create loop
    
    cout << "Before removing loop" << endl;
    removeLoop(head1);
    cout << "After removing loop" << endl;
    
    // Print list to verify
    Node* temp = head1;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
    return 0;
}