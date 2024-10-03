using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

bool check(BinaryTree* root1, BinaryTree* root2) {
    if (root1==nullptr&&root2==nullptr) {
        return true;
    }
    if (root1==nullptr||root2==nullptr) {
        return false;
    }

    if (root1->value==root2->value) {
        return check(root1->left,root2->right) && check(root1->right,root2->left);
    }

    return false;
}

bool symmetricalTree(BinaryTree* tree) {
    return check(tree->left, tree->right);
}
