using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* traverse(TreeNode* root) {
    if (root==nullptr) {
        return nullptr;
    }

    TreeNode* left=traverse(root->left);
    TreeNode* right=traverse(root->right);

    if (left==nullptr) {
        root->right=right;
        return root;
    }
    if (right==nullptr) {
        root->right=left;
        root->left=nullptr;
        return root;
    }

    root->left=nullptr;
    root->right=left;

    while (left->right!=nullptr) {
        left=left->right;
    }

    left->right=right;
    return root;
}

void flatten(TreeNode* root) {
    root=traverse(root);
    return;
}