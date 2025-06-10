// Problem: Rearrange a linked list
// Difficulty: MediumAccuracy: 44.26%Submissions: 48K+Points: 4Average Time: 20m
// Given a singly linked list, the task is to rearrange it in a way that all odd position nodes are together and all even position nodes are together. (Considering 1-based indexing.)

// Note: You should place all odd-positioned nodes first and then the even-positioned ones. Also, the relative order of odd-positioned nodes and even-positioned nodes should be maintained. 

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void rearrangeEvenOdd(Node *head){
    if(!head->next){
        return;
    }

    Node *first = head, *second = head->next, *temp = head->next;

    while(second && second->next){
        first->next = second->next;
        first = first->next;
        second->next = first->next;
        second = second->next;
    }

    first->next = temp;
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
    Node *head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};

    printList(head);
    cout << endl;
    rearrangeEvenOdd(head);
    cout << "After rearrange: ";
    printList(head);
    return 0;
}