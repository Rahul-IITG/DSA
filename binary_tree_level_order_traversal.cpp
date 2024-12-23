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
       queue<TreeNode*> q;
       q.push(root);
       vector<vector<int>> sol;
       int s=1;
       vector<int> level;

       while (s) {
              TreeNode* curr=q.front();
              level.push_back(curr->val);
              q.pop();
              s--;

              if (curr->left!=nullptr) {
                     q.push(curr->left);
              }
              if (curr->right!=nullptr) {
                     q.push(curr->right);
              }

              if (s==0) {
                     sol.push_back(level);
                     level.clear();
                     s=q.size();
              }
       }

       return sol;
}