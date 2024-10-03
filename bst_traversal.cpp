#include <vector>
using namespace std;

class BST {
public:
    int value;
    BST* left;
    BST* right;

    BST(int val);
};

void inOrderTraverse(BST* tree, vector<int>& array) {
    if (tree==nullptr) {
        return;
    }

    if (tree->left!=nullptr) {
        inOrderTraverse(tree->left,array);
    }

    array.push_back(tree->value);

    if (tree->right!=nullptr) {
        inOrderTraverse(tree->right,array);
    }
}

void preOrderTraverse(BST* tree, vector<int>& array) {
    if (tree==nullptr) {
        return;
    }

    array.push_back(tree->value);

    if (tree->left!=nullptr) {
        inOrderTraverse(tree->left,array);
    }

    if (tree->right!=nullptr) {
        inOrderTraverse(tree->right,array);
    }
}

void postOrderTraverse(BST* tree, vector<int>& array) {
    if (tree==nullptr) {
        return;
    }

    if (tree->left!=nullptr) {
        inOrderTraverse(tree->left,array);
    }

    if (tree->right!=nullptr) {
        inOrderTraverse(tree->right,array);
    }

    array.push_back(tree->value);
}
