#include <vector>
using namespace std;

class AncestralTree {
public:
    char name;
    AncestralTree* ancestor;

    AncestralTree(char name) {
        this->name = name;
        this->ancestor = nullptr;
    }

    void addAsAncestor(vector<AncestralTree*> descendants);
};

void traverse(AncestralTree* root, vector<AncestralTree*> &lst) {
    if (root==nullptr) {
        return;
    }

    traverse(root->ancestor, lst);
    lst.push_back(root);
    return;
}

AncestralTree* getYoungestCommonAncestor(
  AncestralTree* topAncestor,
  AncestralTree* descendantOne,
  AncestralTree* descendantTwo) {
    vector<AncestralTree*> one;
    vector<AncestralTree*> two;
    traverse(descendantOne,one);
    traverse(descendantTwo,two);

    int os=one.size();
    int ts=two.size();
    int i=0;
    int j=0;

    AncestralTree* sol;

    while (i<os&&j<ts) {
        if (one[i]->name==two[j]->name) {
            sol=one[i];
            i++;
            j++;
            continue;
        }

        break;
    }

    return sol;
}