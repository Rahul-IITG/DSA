#include <vector>
using namespace std;

vector<int> sweetAndSavory(vector<int> dishes, int target) {
    int s=dishes.size();
    vector<int> pos;
    vector<int> neg;

    for (int i=0;i<s;i++) {
        if (dishes[i]<0) {
            neg.push_back(dishes[i]);
        }
        else {
            pos.push_back(dishes[i]);
        }
    }

    sort(pos.begin(),pos.end());
    sort(neg.begin(), neg.end());
    reverse(neg.begin(),neg.end());

    int i=0;
    int j=0;
    int is=neg.size();
    int js=pos.size();
    int first=0;
    int second=0;
    int diff=10000;

    if (is==0||js==0) {
        return vector<int>(2,0);
    }

    while (i<is&&j<js) {
        if (target-(neg[i]+pos[j])<diff && target>(neg[i]+pos[j])) {
            first=neg[i];
            second=pos[j];
        }
        if (neg[i]+pos[j]==target) {
            vector<int> sol;
            sol.push_back(neg[i]);
            sol.push_back(pos[j]);
            return sol;
        }
        if (target<0) {
            if (neg[i]+pos[j]<target) {
                j++;
                continue;
            }

            i++;
            continue;
        }
        if (target>=0) {
            if (neg[i]+pos[j]<target) {
                j++;
                continue;
            }

            i++;
            continue;
        }
    }

    vector<int> sol;
    sol.push_back(first);
    sol.push_back(second);
    return sol;
}
