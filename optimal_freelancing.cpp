#include <unordered_map>
#include <vector>
using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
    return a[1]>b[1];
}

int optimalFreelancing(vector<unordered_map<string, int>> jobs) {
    int s = jobs.size();
    vector<vector<int>> lst;

    for (int i=0;i<s;i++) {
        vector<int> curr;
        curr.push_back(jobs[i]["deadline"]);
        curr.push_back(jobs[i]["payment"]);
        lst.push_back(curr);
    }

    sort(lst.begin(), lst.end(), comp);
    vector<int> week(7, 0);
    int ans=0;
    int index;

    for (int i=0;i<s;i++) {
        index=min(lst[i][0]-1,6);
        if (week[index]==0) {
            ans=ans+lst[i][1];
            week[index]=1;
            continue;
        }

        for (int j=index;j>=0;j--) {
            if (week[j]==0) {
                ans=ans+lst[i][1];
                week[j]=1;
                break;
            }
        }

        if (week[0]==1) {
            break;
        }
    }

    return ans;
}

