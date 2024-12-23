#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> rightSideView(TreeNode* root) {
    if (root==nullptr) {
        return {};
    }

    vector<int> sol;
    queue<TreeNode*> q;
    q.push(root);
    int s=1;

    while (s) {
        TreeNode* curr=q.front();
        q.pop();
        s--;

        if (curr->left!=nullptr) {
            q.push(curr->left);
        }
        if (curr->right!=nullptr) {
            q.push(curr->right);
        }

        if (s==0) {
            sol.push_back(curr->val);
            s=q.size();
        }
    }

    return sol;
}