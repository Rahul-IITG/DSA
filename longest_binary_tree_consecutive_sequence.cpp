#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

void traverse(Node* root, int length, int &ans) {
    if (root==nullptr) {
        return;
    }

    if (length>ans) {
        ans=length;
    }

    if (root->left!=nullptr&&root->left->data==root->data+1) {
        traverse(root->left,length+1,ans);
    }
    else {
        traverse(root->left,1,ans);
    }

    if (root->right!=nullptr&&root->right->data==root->data+1) {
        traverse(root->right,length+1,ans);
    }
    else {
        traverse(root->right,1,ans);
    }

    return;
}

int longestConsecutive(Node* root) {
    int length=1;
    int ans=INT_MIN;
    traverse(root,length,ans);
    return ans == 1 ? -1 : ans;
}