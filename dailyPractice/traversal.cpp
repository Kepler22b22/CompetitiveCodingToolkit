#include <iostream>
#include <stack>

using namespace std;

class Node{
public:
    int val;
    Node *left;
    Node *right;

    Node(int v): val(v), left(NULL), right(NULL) {}
};

void preorderR(Node *root){
    if(!root){return;}
    cout << root->val << " ";
    preorderR(root->left);
    preorderR(root->right);
}

void preorderI(Node *root){
    if(!root){return;}
    stack<Node*> stk;
    stk.push(root);
    while(!stk.empty()){
        Node *cur = stk.top();
        stk.pop();
        cout << cur->val << " ";
        if(cur->right){stk.push(cur->right);}
        if(cur->left){stk.push(cur->left);}
    }
}

void inorderR(Node *root){
    if(!root){return;}
    inorderR(root->left);
    cout << root->val << " ";
    inorderR(root->right);
}

void inorderI(Node *root){
    if(!root){return;}
    stack<Node*> stk;
    Node *cur = root;
    while(!stk.empty() || cur){
        while(cur){
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        cout << cur->val << " ";
        cur = cur->right;
    }
}

void postorderR(Node *root){
    if(!root){return;}
    postorderR(root->left);
    postorderR(root->right);
    cout << root->val << " ";
}

void postorderI(Node *root){
    if(!root){return;}
    stack<Node*> stk;
    Node *cur = root, *lastVisit = NULL;
    while(!stk.empty() || cur){
        while(cur){
            stk.push(cur);
            cur = cur->left;
        }
        if(stk.top()->right && lastVisit != stk.top()->right){
            cur = stk.top()->right;
        }
        else{
            lastVisit = stk.top();
            cout << stk.top()->val << " ";
            stk.pop();
        }
    }
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

    return 0;
}