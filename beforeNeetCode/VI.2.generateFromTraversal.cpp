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

class Tree{
private:
    int preidx = 0;
    int inidx = 0;

    Node * dfs(vector<int> &pre, vector<int> &in, int limit){
        if(preidx >= pre.size()){return NULL;}
        if(in[inidx] == limit){
            inidx++;
            return NULL;
        }
        Node *root = new Node(pre[preidx++]);
        root->left = dfs(pre, in, root->val);
        root->right = dfs(pre, in, limit);
        return root;
    }

public:
    Node * generate(vector<int> &pre, vector<int> &in){
        return dfs(pre, in, INT_MAX);
    }
};


// Function to print the tree (inorder traversal)
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Function to print the tree (preorder traversal)
void printPreorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    // Test inputs
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Build the tree
    Tree tree;
    Node* root = tree.generate(preorder, inorder);

    // Print the reconstructed tree to verify correctness
    cout << "Inorder traversal of the reconstructed tree: ";
    printInorder(root);
    cout << endl;

    cout << "Preorder traversal of the reconstructed tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}