#include <queue>
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

vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> sol;
       if (root==nullptr) {
              return sol;
       }
       queue<TreeNode*> q;
       q.push(root);
       vector<int> curr;
       int s=1;

       while (s) {
              TreeNode* node=q.front();
              q.pop();
              s--;
              curr.push_back(node->val);

              if (node->left!=nullptr) {
                     q.push(node->left);
              }
              if (node->right!=nullptr) {
                     q.push(node->right);
              }

              if (s==0) {
                     s=q.size();
                     sol.push_back(curr);
                     curr.clear();
              }
       }

       return sol;
}