#include <algorithm>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

int traverse(BinaryTree* root, int &ans) {
    if (root==nullptr) {
        return 0;
    }

    int leftHeight=traverse(root->left,ans);
    int rightHeight=traverse(root->right,ans);

    if (leftHeight+rightHeight>ans) {
        ans=leftHeight+rightHeight;
    }

    return max(leftHeight+1,rightHeight+1);
}

int binaryTreeDiameter(BinaryTree* tree) {
    int ans=0;
    traverse(tree,ans);
    return ans;
}