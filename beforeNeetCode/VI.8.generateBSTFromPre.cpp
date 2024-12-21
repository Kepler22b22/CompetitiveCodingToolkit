#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    Node *left;
    Node *right;
    int val;

    Node(int v): val(v), left(NULL), right(NULL){}
};

Node * dfs(vector<int> &preorder, int &preidx, int limit){
    if(preidx >= preorder.size() || preorder[preidx] > limit){return NULL;}
    Node *root = new Node(preorder[preidx++]);
    root->left = dfs(preorder, preidx, root->val);
    root->right = dfs(preorder, preidx, limit);
    return root;
}

Node * generate(vector<int> &preorder){
    int preidx = 0;
    return dfs(preorder, preidx, INT_MAX);
}

// Helper function to print the tree in inorder traversal
void printInorder(Node *root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Main function to test the tree generation
int main() {
    vector<int> preorder1 = {8, 5, 1, 7, 10, 12};

    Node *root1 = generate(preorder1);

    cout << "Inorder Traversal of Generated Tree: ";
    printInorder(root1);
    cout << endl;

    vector<int> preorder2 = {30, 20, 10, 15, 25, 40, 50, 45};

    Node *root2 = generate(preorder2);

    cout << "Inorder Traversal of Generated Tree: ";
    printInorder(root2);
    cout << endl;

    return 0;
}