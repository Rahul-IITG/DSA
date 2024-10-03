#include <algorithm>
#include <cmath>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

int traverse(BinaryTree* root, bool &flag) {
    if (root==nullptr) {
        return 0;
    }

    int leftH=traverse(root->left,flag);
    int rightH=traverse(root->right,flag);

    if (abs(leftH-rightH)>1) {
        flag=false;
    }

    return max(leftH+1, rightH+1);
}

bool heightBalancedBinaryTree(BinaryTree* tree) {
    bool flag=true;
    traverse(tree,flag);
    return flag;
}
