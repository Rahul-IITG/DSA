using namespace std;

// This is an input class. Do not edit.
class BST {
public:
    int value;
    BST* left = nullptr;
    BST* right = nullptr;

    BST(int value) { this->value = value; }
};

bool isChild(BST* root, BST* child) {
    if (root==nullptr) {
        return false;
    }

    if (root->value==child->value) {
        return true;
    }

    if (root->value>child->value) {
        return isChild(root->left,child);
    }

    if (root->value<child->value) {
        return isChild(root->right,child);
    }

    return false;
}

bool validateThreeNodes(BST* nodeOne, BST* nodeTwo, BST* nodeThree) {
    return (isChild(nodeTwo, nodeOne) && isChild(nodeThree, nodeTwo)) || (isChild(nodeTwo, nodeThree) && isChild(nodeOne, nodeTwo));
}
