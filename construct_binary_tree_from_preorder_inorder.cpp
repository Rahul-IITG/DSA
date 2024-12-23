#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int s=inorder.size();

    if (s==0) {
        return nullptr;
    }

    TreeNode* root;
    root=new TreeNode(preorder[0]);
    preorder.erase(preorder.begin());
    vector<int> leftV;
    vector<int> rightV;
    bool flag=false;

    for (int i=0;i<s;i++) {
        if (inorder[i]==root->val) {
            flag=true;
            continue;
        }
        if (flag) {
            rightV.push_back(inorder[i]);
            continue;
        }

        leftV.push_back(inorder[i]);
    }

    root->left=buildTree(preorder,leftV);
    root->right=buildTree(preorder,rightV);
    return root;
}