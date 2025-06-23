#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

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

void levelOrder(Node *root){
    if(!root){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cout << temp->data;
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

int main(){

    Node *root = binaryTree();

    levelOrder(root);
    return 0;
}