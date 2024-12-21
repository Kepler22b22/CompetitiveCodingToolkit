#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node{
public:
    Node *left;
    Node *right;
    int val;

    Node(int v): val(v), left(NULL), right(NULL){}
};

void preorderRecursive(Node *root){
    if(!root){return;}
    Node *temp = root;
    cout << temp->val << " ";
    preorderRecursive(temp->left);
    preorderRecursive(temp->right);
}

void preorderIterative(Node *root){
    if(!root){return;}
    stack<Node *> st;
    st.push(root);
    while(!st.empty()){
        Node *temp = st.top();
        st.pop();
        cout << temp->val << " ";
        if(temp->right){st.push(temp->right);}
        if(temp->left){st.push(temp->left);}
    }
}

void inorderIterative(Node *root){
    if(!root){return;}
    stack<Node *> st;
    Node *temp = root;
    while(temp || !st.empty()){
        while(temp){
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        cout << temp->val << " ";
        temp = temp->right;
    }
}

void postorderIterative(Node *root){
    if(!root){return;}
    stack<Node *> st;
    Node *temp = root;
    Node *lastVisit = NULL;
    while(temp || !st.empty()){
        while(temp){
            st.push(temp);
            temp = temp->left;
        }
        Node *top = st.top();
        if(top->right && lastVisit != top->right){
            temp = top->right;
        }
        else{
            lastVisit = top;
            cout << top->val << " ";
            st.pop();
        }
    }
}

void levelOrder(Node *root){
    if(!root){return;}
    queue<Node *> q;
    Node *temp = root;
    q.push(temp);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if(temp->left){q.push(temp->left);}
        if(temp->right){q.push(temp->right);}
    }
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Perform preorder traversal
    cout << "Preorder Traversal: ";
    preorderIterative(root);
    cout << endl;

    // Perform inorder traversal
    cout << "Inorder Traversal: ";
    inorderIterative(root);
    cout << endl;

    // Perform postorder traversal
    cout << "Postorder Traversal: ";
    postorderIterative(root);
    cout << endl;

    // Perform level order traversal
    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;

    // Cleanup memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
 
}