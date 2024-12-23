#include <queue>
#include <vector>
using namespace std;

bool comp_func(vector<int> &a, vector<int> &b) {
    return a[0]<b[0];
}

int minMeetingRooms(vector<vector<int>>& intervals) {
    int s=intervals.size();

    if (s==0||s==1) {
        return s;
    }

    sort(intervals.begin(),intervals.end(),comp_func);
    priority_queue<int,vector<int>, greater<int>> pq;
    pq.push(intervals[0][1]);

    for (int i=1;i<s;i++) {
        if (!pq.empty()&&pq.top()<=intervals[i][0]) {
            pq.pop();
        }

        pq.push(intervals[i][1]);
    }

    return pq.size();
}