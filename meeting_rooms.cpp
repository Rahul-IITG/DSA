#include <vector>
using namespace std;

bool comp_func(vector<int> &a, vector<int> &b) {
    return a[1]<b[1];
}

bool canAttendMeetings(vector<vector<int>>& intervals) {
    int s=intervals.size();

    if (s==0||s==1) {
        return true;
    }

    sort(intervals.begin(),intervals.end(),comp_func);
    int first=intervals[0][0];
    int second=intervals[0][1];

    for (int i=1;i<s;i++) {
        if (second>intervals[i][0]) {
            return false;
        }
        else {
            second=intervals[i][1];
        }
    }

    return true;
}