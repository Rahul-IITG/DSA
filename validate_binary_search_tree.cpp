#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inOrder(TreeNode* root, vector<int> &inorder) {
    if (root==nullptr) {
        return;
    }

    inOrder(root->left,inorder);
    inorder.push_back(root->val);
    inOrder(root->right,inorder);

    return;
}

bool isValidBST(TreeNode* root) {
    if (root==nullptr) {
        return true;
    }

    vector<int> inorder;
    inOrder(root,inorder);
    int s=inorder.size();

    for (int i=0;i<s-1;i++) {
        if (inorder[i]>=inorder[i+1]) {
            return false;
        }
    }

    return true;
}