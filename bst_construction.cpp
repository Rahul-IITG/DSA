class BST {
public:
    int value;
    BST* left;
    BST* right;

    BST(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }

    BST& insert(int val) {
        if (this->value<=val) {
            if (this->right==nullptr) {
                this->right=new BST(val);
                return *this;
            }

            this->right=&this->right->insert(val);
        }

        if (this->value>val) {
            if (this->left==nullptr) {
                this->left=new BST(val);
                return *this;
            }

            this->left=&this->left->insert(val);
        }

        return *this;
    }

    bool contains(int val) {
        if (this->value==val) {
            return true;
        }

        if (this->value<val) {
            return this->right->contains(val);
        }
        if (this->value>val) {
            return this->left->contains(val);
        }

        return false;
    }

    BST& remove(int val) {
        if (this->left==nullptr&&this->right==nullptr) {
            return *this;
        }

        return *removeVal(this, val);;
    }

    BST* removeVal(BST* root, int val) {
        if (root->value==val) {
            int newVal;
            if (root->right!=nullptr) {
                BST* next=findNext(root->right, newVal);
                BST* newRoot=new BST(newVal);
                newRoot->left=root->left;
                newRoot->right=next;
                return newRoot;
            }
            if (root->left!=nullptr) {
                return root->left;
            }
        }
        if (root->value<val&&root->right!=nullptr) {
            root->right=removeVal(root->right, val);
            return root;
        }
        if (root->value>val&&root->left!=nullptr) {
            root->left=removeVal(root->left,val);
            return root;
        }

        return root;
    }

    BST* findNext(BST* root, int &newVal) {
        if (root->left==nullptr&&root->right==nullptr) {
            newVal=root->value;
            return nullptr;
        }
        if (root->left==nullptr) {
            newVal=root->value;
            return root->right;
        }
        if (root->left!=nullptr) {
            root->left=findNext(root->left, newVal);
            return root;
        }

        newVal=root->value;
        return root->right;
    }
};