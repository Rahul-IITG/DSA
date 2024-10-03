#include <vector>
using namespace std;

bool comp_func(vector<int> &a, vector<int> &b) {
    return a[0]<b[0];
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);
    int s=intervals.size();
    sort(intervals.begin(),intervals.end(),comp_func);

    vector<vector<int>> sol;
    vector<int> curr;
    curr=intervals[0];

    for (int i=1;i<s;i++) {
        if (curr[1]<intervals[i][0]) {
            sol.push_back(curr);
            curr=intervals[i];
            continue;
        }
        if (curr[1]>=intervals[i][0]) {
            curr[1]=max(curr[1],intervals[i][1]);
            continue;
        }
    }

    sol.push_back(curr);
    return sol;
}