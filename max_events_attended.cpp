#include <queue>
#include <vector>
using namespace std;

bool comp_func(vector<int> &a, vector<int> &b) {
    return a[0]<b[0];
}

int maxEvents(vector<vector<int>>& events) {
    int s=events.size();
    sort(events.begin(),events.end(),comp_func);

    priority_queue<int,vector<int>,greater<int>> pq;
    int count=0;
    int i=0;

    for (int day=1;day<=100000;day++) {
        while (!pq.empty()&&pq.top()<day) {
            pq.pop();
        }

        while (i<s&&events[i][0]==day) {
            pq.push(events[i][1]);
            i++;
        }

        if (!pq.empty()) {
            pq.pop();
            count++;
        }

        if (pq.empty()&&i==s) {
            break;
        }
    }

    return count;
}
