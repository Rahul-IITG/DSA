using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

BinaryTree* mergeBinaryTrees(BinaryTree* tree1, BinaryTree* tree2) {
    if (tree1==nullptr&&tree2==nullptr) {
        return nullptr;
    }

    if (tree1==nullptr) {
        return tree2;
    }
    if (tree2==nullptr) {
        return tree1;
    }

    BinaryTree* root=new BinaryTree(tree1->value+tree2->value);
    root->left=mergeBinaryTrees(tree1->left, tree2->left);
    root->right=mergeBinaryTrees(tree1->right, tree2->right);
    return root;
}