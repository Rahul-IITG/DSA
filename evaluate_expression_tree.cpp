class BinaryTree {
 public:
  int val;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

int evaluateExpressionTree(BinaryTree* tree) {
    if (tree->left == NULL && tree->right == NULL) {
        return tree->val;
    }
    if (tree->val == -1) {
        return evaluateExpressionTree(tree->left) + evaluateExpressionTree(tree->right);
    }
    if (tree->val == -2) {
        return evaluateExpressionTree(tree->left) - evaluateExpressionTree(tree->right);
    }
    if (tree->val == -3) {
        return evaluateExpressionTree(tree->left) / evaluateExpressionTree(tree->right);
    }
    if (tree->val == -4) {
        return evaluateExpressionTree(tree->left) * evaluateExpressionTree(tree->right);
    }
}