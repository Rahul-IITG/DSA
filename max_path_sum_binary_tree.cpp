#include <vector>
using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value);
    void insert(vector<int> values, int i = 0);
};

int maxPathSum(BinaryTree tree) {
    // Write your code here.
    return -1;
}