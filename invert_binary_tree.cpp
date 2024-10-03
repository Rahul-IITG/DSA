#include <vector>
using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value);
    void insert(vector<int> values, int i = 0);
    void invertedInsert(vector<int> values, int i = 0);
};

BinaryTree* invert(BinaryTree* root) {
    if (root==nullptr) {
        return nullptr;
    }

    root->left=invert(root->right);
    root->right=invert(root->left);

    return root;
}

void invertBinaryTree(BinaryTree* tree) {
    tree=invert(tree);
    return;
}