#include <queue>

using namespace std;
class BST {
public:
    int value;
    BST* left;
    BST* right;

    BST(int val);
    BST& insert(int val);
};

bool traverse(BST* root, int min, int max) {
    if (root==nullptr) {
        return true;
    }

    if (root->value>=max || root->value<min) {
        return false;
    }

    return traverse(root->left, min, root->value) && traverse(root->right, root->value,max);
}

bool validateBst(BST* tree) {
    if (tree==nullptr) {
        return true;
    }

    return traverse(tree, INT_MIN, INT_MAX);
}