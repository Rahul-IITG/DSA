#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inOrder(TreeNode* root, int &count, int &k, int &sol) {
    if (root==nullptr) {
        return;
    }

    inOrder(root->left,count,k,sol);
    count++;

    if (count==k) {
        sol=root->val;
    }

    inOrder(root->right,count,k,sol);
}

int kthSmallest(TreeNode* root, int k) {
    if (root==nullptr) {
        return -1;
    }

    int count=0;
    int sol;
    inOrder(root,count,k,sol);

    return sol;
}