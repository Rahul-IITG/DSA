#include <vector>
using namespace std;

using namespace std;
class BST {
public:
 int value;
 BST* left;
 BST* right;

 BST(int val);
 BST& insert(int val);
};

BST* constructBST(vector<int> array, int start, int end) {
    if (start>end) {
        return nullptr;
    }
    if (start==end) {
        BST* root=new BST(array[start]);
        root->left=nullptr;
        root->right=nullptr;
        return root;
    }

    int middle=(start+end)/2;

    BST* root=new BST(array[middle]);
    root->left=constructBST(array, start, middle-1);
    root->right=constructBST(array, middle+1, end);

    return root;
}

BST* minHeightBst(vector<int> array) {
    int s=array.size();
    return constructBST(array, 0, s-1);
}
