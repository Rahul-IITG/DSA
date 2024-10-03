class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

void traverse(BinaryTree* root, int &sol, int depth) {
    if (root == NULL) {
        return;
    }

    sol = sol +depth;
    traverse(root->left,sol,depth+1);
    traverse(root->right,sol,depth+1);
    return;
}

int nodeDepths(BinaryTree* root) {
    int sol = 0;
    int depth = 0;
    traverse(root, sol, depth);

    return sol;
}