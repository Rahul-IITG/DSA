#include <vector>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;
    BinaryTree* parent = nullptr;

    BinaryTree(int value) { this->value = value; }
};

void traverse(BinaryTree* root, vector<BinaryTree*> &inorder) {
    if (root==nullptr) {
        return;
    }

    traverse(root->left, inorder);
    inorder.push_back(root);
    traverse(root->right, inorder);
    return;
}

BinaryTree* findSuccessor(BinaryTree* tree, BinaryTree* node) {
    vector<BinaryTree*> inorder;
    traverse(tree,inorder);

    int s=inorder.size();
    int index=0;

    while (index<s) {
        if (inorder[index]==node) {
            index++;
            break;
        }
        index++;
    }

    if (index<s) {
        return inorder[index];
    }

    return nullptr;
}