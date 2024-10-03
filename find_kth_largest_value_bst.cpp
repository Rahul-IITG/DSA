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

void traverse(BST* tree, vector<int> &array) {
    if (tree==nullptr) {
        return;
    }

    if (tree->left!=nullptr) {
        traverse(tree->left,array);
    }

    array.push_back(tree->value);

    if (tree->right!=nullptr) {
        traverse(tree->right,array);
    }
}

int findKthLargestValueInBst(BST* tree, int k) {
    vector<int> inorder;
    traverse(tree,inorder);
    int s=inorder.size();

    for (int i=s-1;i>=0;i--) {
        k--;

        if (k==0) {
            return inorder[i];
        }
    }

    return -1;
}