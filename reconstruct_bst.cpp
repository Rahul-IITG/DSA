#include <vector>
using namespace std;

// This is an input class. Do not edit.
class BST {
public:
    int value;
    BST* left = nullptr;
    BST* right = nullptr;

    BST(int value) { this->value = value; }
};

BST* constructBST(vector<int> preOrder, int start, int end) {
    if (start>end) {
        return nullptr;
    }
    if (start==end) {
        BST* root=new BST(preOrder[start]);
        root->left=nullptr;
        root->right=nullptr;
        return root;
    }

    BST* root=new BST(preOrder[start]);
    int index=end+1;

    for (int i=start+1;i<=end;i++) {
        if (preOrder[i]>=preOrder[start]) {
            index=i;
            break;
        }
    }

    root->left=constructBST(preOrder,start+1,index-1);
    root->right=constructBST(preOrder,index, end);
    return root;
}

BST* reconstructBst(vector<int> preOrderTraversalValues) {
    int s=preOrderTraversalValues.size();
    BST* root=constructBST(preOrderTraversalValues, 0, s-1);
    return root;
}
