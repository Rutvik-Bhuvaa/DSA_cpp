// Problem: Find the Sum of Last N nodes of the Linked List
// Given a single linked list, calculate the sum of the last n nodes.

// Note: It is guaranteed that n <= number of nodes.


#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

int sumOfLastN(Node *head, int n){
    int count = 0;
    Node *temp = head;

    // count total nodes
    while(temp){
        count++;
        temp = temp->next;
    }

    // Skip (count - n) nodes
    temp = head;
    for(int i=0; i<count-n; i++){
        temp = temp->next;
    }

    //  Sum last n nodes
    int sum = 0;
    while(temp){
        sum += temp->data;
        temp = temp->next;
    }

    return sum;

}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    int n;
    cout << "Enter the no. of nodes: " << endl;
    cin >> n;
    int result = sumOfLastN(head, n);

    cout << "Sum of last " << n << " nodes is: " << result << endl;

    return 0;
}