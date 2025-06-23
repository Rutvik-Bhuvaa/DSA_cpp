#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *binaryTree(){
    int x;
    cout << "Enter the value: " << endl;
    cin >> x;

    if(x == -1){
        return nullptr;
    }

    Node *root = new Node(x);
    cout << "Enter the left child of " << x << endl;
    root->left = binaryTree();
    cout << "Enter the right child of " << x << endl;
    root->right = binaryTree();

    return root;
}

void postOrder(Node *root){
    if(!root){
        return;
    }
    
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(){
    Node *root = binaryTree();

    postOrder(root);
    
    return 0;
}