#include <vector>
using namespace std;

class OrgChart {
public:
    char name;
    vector<OrgChart*> directReports;

    OrgChart(char name) {
        this->name = name;
        this->directReports = {};
    }

    void addDirectReports(vector<OrgChart*> directReports);
};

void traverse(OrgChart* root, OrgChart* child, bool &flag, vector<OrgChart*> path) {
    if (root->name==child->name) {
        flag=true;
        path.push_back(child);
        return;
    }
    int s=root->directReports.size();

    for (int i=0;i<s;i++) {
        if (flag) {
            break;
        }
        traverse(root->directReports[i],child,flag,path);
    }

    if (flag) {
        path.push_back(root);
    }

    return;
}

OrgChart* getLowestCommonManager(OrgChart* topManager, OrgChart* reportOne, OrgChart* reportTwo) {
    vector<OrgChart*> one;
    vector<OrgChart*> two;
    bool flag=false;
    traverse(topManager,reportOne,flag,one);
    flag=false;
    traverse(topManager,reportTwo,flag,two);
    reverse(one.begin(),one.end());
    reverse(two.begin(),two.end());

    int s=min(one.size(),two.size());

    for (int i=0;i<s;i++) {
        if (one[i]->name!=two[i]->name) {
            return one[i-1];
        }
    }

    return nullptr;
}
