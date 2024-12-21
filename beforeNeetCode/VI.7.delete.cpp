#include <iostream>
using namespace std;

class Node{
public:
    Node *left;
    Node * right;
    int val;

    Node(int v): val(v), left(NULL), right(NULL){}
};

/*Node* InPre(Node *p) {
    while (p && p->right != NULL){
        p = p->right;
    }
    return p;
}*/
 
/*Node* InSucc(Node *p) {
    while (p && p->left != NULL){
        p = p->left;
    }
    return p;
}*/

Node * deleteFromBST(Node *root, int key){
    if(!root){return root;}
    if(key < root->val){root->left = deleteFromBST(root->left, key);}
    else if(key > root->val){root->right = deleteFromBST(root->right, key);}
    else{
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        else if(!root->left || !root->right){return root->left? root->left : root->right;}
        else{
/*            Node *inPre = InPre(root->left);
            root->val = inPre->val;
            root->left = deleteFromBST(root->left, inPre->val);*/
            Node *temp = root->left;
            while(temp->right){temp = temp->right;}
            root->val = temp->val;
            root->left = deleteFromBST(root->left, temp->val);
        }
    }
    return root;
}