#include <vector>
using namespace std;

// This is an input class. Do not edit.
class BST {
public:
    int value;
    BST* left = nullptr;
    BST* right = nullptr;

    BST(int value) { this->value = value; }
};

void inOrder(BST* root, vector<BST*> &inorder) {
    if (root==nullptr) {
        return;
    }

    inOrder(root->left,inorder);
    inorder.push_back(root);
    inOrder(root->right, inorder);
    return;
}

bool comp_func(BST* &a, BST* &b) {
    return a->value<b->value;
}

BST* repairBst(BST* tree) {
    vector<BST*> inorder;
    inOrder(tree, inorder);

    vector<BST*> copy=inorder;
    sort(copy.begin, copy.end(), comp_func);

    int s=inorder.size();
    vector<BST*> nodes;

    for (int i=0;i<s;i++) {
        if (copy[i]->value!=inorder[i]->value) {
            nodes.push_back(inorder[i]);
        }
    }

    int temp=nodes[0]->value;
    nodes[0]->value=nodes[1]->value;
    nodes[1]->value=temp;

    return tree;
}