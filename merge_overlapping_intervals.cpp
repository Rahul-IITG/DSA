#include <vector>
using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
    return a[0]<b[0];
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
    int s=intervals.size();
    sort(intervals.begin(), intervals.end(), comp);

    if (s==0||s==1) {
        return intervals;
    }

    int first=intervals[0][0];
    int second=intervals[0][1];
    vector<vector<int>> sol;

    for (int i=1;i<s;i++) {
        if (first==intervals[i][0]) {
            if (second<intervals[i][1]) {
                second=intervals[i][1];
            }
            continue;
        }
        if (second>=intervals[i][0]) {
            if (second<intervals[i][1]) {
                second=intervals[i][1];
            }
            continue;
        }
        if (second<intervals[i][0]) {
            vector<int> curr;
            curr.push_back(first);
            curr.push_back(second);
            sol.push_back(curr);
            first=intervals[i][0];
            second=intervals[i][1];
        }
    }

    vector<int> curr;
    curr.push_back(first);
    curr.push_back(second);
    sol.push_back(curr);

    return sol;
}
