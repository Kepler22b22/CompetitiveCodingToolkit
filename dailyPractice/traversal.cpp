#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Node {
public:
    Node *left, *right;
    int val;

    Node(int v): val(v), left(nullptr), right(nullptr) {}
};

void preorderR(Node *root){
    if(!root){return;}
    cout << root->val << " ";
    preorderR(root->left);
    preorderR(root->right);
}

void preorderI(Node *root){
}

void inorderR(Node *root){
}

void inorderI(Node *root){
}

void postorderR(Node *root){
    if(!root){return;}
    postorderR(root->left);
    postorderR(root->right);
    cout << root->val << " ";
}

void postorderI(Node *root){
}

void levelOrder(Node *root){
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Perform preorder traversal
    cout << "Preorder Traversal I: ";
    preorderR(root);
    cout << endl;

    // Perform preorder traversal II
    cout << "Preorder Traversal II: ";
    preorderI(root);
    cout << endl;

    // Perform inorder traversal I
    cout << "Inorder Traversal I: ";
    inorderR(root);
    cout << endl;

    // Perform inorder traversal II
    cout << "Inorder Traversal II: ";
    inorderI(root);
    cout << endl;

    // Perform postorder traversal I
    cout << "Postorder Traversal I: ";
    postorderR(root);
    cout << endl;

    // Perform postorder traversal II
    cout << "Postorder Traversal II: ";
    postorderI(root);
    cout << endl;

    // Perform levelorder traversal II
    cout << "Levelorder Traversal I: ";
    levelOrder(root);
    cout << endl;

    return 0;
}