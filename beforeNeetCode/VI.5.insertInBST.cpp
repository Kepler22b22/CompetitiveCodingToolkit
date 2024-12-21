#include <iostream>
using namespace std;

class Node{
public:
    Node *left;
    Node *right;
    int val;

    Node(int v): val(v), left(NULL), right(NULL){}
};

Node * insertIterative(Node *root, int key){
    if(!root){
        root = new Node(key);
        return root;
    }
    Node *p = root, *r = NULL;
    while(p){
        r = p;
        if(key == p->val){return root;}
        else if(key > p->val){p = p->right;}
        else{p = p->left;}
    }
    Node *node = new Node(key);
    if(key > r->val){r->right = node;}
    else{r->left = node;}
    return root;
}

Node * insertRecursive(Node *root, int key){
    if(!root){
        root= new Node(key);
        return root;
    }
    if(key > root->val){root->right = insertRecursive(root->right, key);}
    else if(key < root->val){root->left = insertRecursive(root->left, key);}
    return root; 
}

void printInorder(Node *root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Node *root = nullptr;

    // Test the recursive insertion
    root = insertRecursive(root, 10);
    root = insertRecursive(root, 5);
    root = insertRecursive(root, 15);
    root = insertRecursive(root, 3);
    root = insertRecursive(root, 7);

    cout << "Inorder Traversal after Recursive Inserts: ";
    printInorder(root);
    cout << endl;

    // Test the iterative insertion
    root = insertIterative(root, 12);
    root = insertIterative(root, 20);

    cout << "Inorder Traversal after Iterative Inserts: ";
    printInorder(root);
    cout << endl;

    return 0;
}