#include <iostream>
#include <vector>
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

int countHeightRecursive(Node *root){
    if(!root){return 0;}
    int leftHeight = countHeightRecursive(root->left);
    int rightHeight = countHeightRecursive(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int countHeightIterativeDFS(Node *root){
    if(!root){return 0;}
    int height = 0;
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    while(!st.empty()){
        pair<Node *, int> cur = st.top();
        st.pop();
        Node *node = cur.first;
        if(node){
            height = max(height, cur.second);
            st.push({node->left, cur.second + 1});
            st.push({node->right, cur.second + 1});
        }
    }
    return height;
}

int countHeightIterativeBFS(Node *root){
    if(!root){return 0;}
    int height = 0;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int levelsize = q.size();
        for(int i = 0; i < levelsize; i++){
            Node *cur = q.front();
            q.pop();
            if(cur->left){q.push(cur->left);}
            if(cur->right){q.push(cur->right);}
        }
        height++;
    }
    return height;
}

// Helper function to create a simple tree
Node* createSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

// Main function to test all three methods
int main() {
    // Create a sample tree
    Node* root = createSampleTree();

    // Test recursive method
    cout << "Height (Recursive): " << countHeightRecursive(root) << endl;

    // Test iterative DFS method
    cout << "Height (Iterative DFS): " << countHeightIterativeDFS(root) << endl;

    // Test iterative BFS method
    cout << "Height (Iterative BFS): " << countHeightIterativeBFS(root) << endl;

    return 0;
}