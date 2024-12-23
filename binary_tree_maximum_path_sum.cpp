#include <algorithm>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int traverse(TreeNode* root, int &ans) {
    if (root==nullptr) {
        return 0;
    }

    int left=traverse(root->left,ans);
    int right=traverse(root->right,ans);
    ans=max(ans,root->val);
    ans=max(ans,max(root->val+left+right,max(root->val+left,root->val+right)));

    return max(root->val,max(root->val+left,root->val+right));
}

int maxPathSum(TreeNode* root) {
    int ans=INT_MIN;
    traverse(root,ans);
    return ans;
}