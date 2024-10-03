#include <unordered_map>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

int traverse(BinaryTree* root, unordered_map<int,int> &umap) {
    if (root==nullptr) {
        return 0;
    }

    int leftSum=traverse(root->left,umap);
    int rightSum=traverse(root->right,umap);

    if (leftSum!=0) {
        umap[leftSum]++;
    }
    if (rightSum!=0) {
        umap[rightSum]++;
    }

    return root->value+leftSum+rightSum;
}

int splitBinaryTree(BinaryTree* tree) {
    unordered_map<int,int> umap;
    int sum=traverse(tree,umap);

    if (umap[sum/2]==1&&sum%2==0) {
        return sum/2;
    }

    return 0;
}