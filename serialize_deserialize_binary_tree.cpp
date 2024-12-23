#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

string serialize(TreeNode* root) {
    string sol="";

    if (root==nullptr) {
        return sol;
    }

    queue<TreeNode*> q;
    q.push(root);
    vector<int> lo;
    lo.push_back(root->val);

    while (!q.empty()) {
        TreeNode* curr=q.front();
        q.pop();

        if (curr->left!=nullptr) {
            lo.push_back(curr->left->val);
            q.push(curr->left);
        }
        else {
            lo.push_back(-10000);
        }

        if (curr->right!=nullptr) {
            lo.push_back(curr->right->val);
            q.push(curr->right);
        }
        else {
            lo.push_back(-10000);
        }
    }

    int s=lo.size();

    for (int i=0;i<s;i++) {
        if (i==s-1) {
            sol=sol+to_string(lo[i]);
            break;
        }

        sol=sol+to_string(lo[i])+",";
    }

    return sol;
}

TreeNode* deserialize(string data) {
    vector<int> values;
    int s=data.size();
    string curr="";

    if (s==0) {
        return nullptr;
    }

    for (int i=0;i<s;i++) {
        if (data[i]==',') {
            values.push_back(stoi(curr));
            curr="";
            continue;
        }

        curr=curr+data[i];

        if (i==s-1) {
            values.push_back(stoi(curr));
        }
    }

    s=values.size();

    TreeNode* head=new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(head);
    int i=1;
    TreeNode* node;

    while (i<s) {
        node=q.front();
        q.pop();

        if (values[i]!=-10000) {
            node->left=new TreeNode(values[i]);
            q.push(node->left);
        }

        i++;

        if (i==s) {
            break;
        }

        if (values[i]!=-10000) {
            node->right=new TreeNode(values[i]);
            q.push(node->right);
        }

        i++;
    }

    return head;
}