#include <vector>
using namespace std;

bool comp_func(vector<int> &a, vector<int> &b) {
    return a[1]<b[1];
}

int maxTwoEvents(vector<vector<int>>& events) {
    int s=events.size();
    sort(events.begin(),events.end(),comp_func);

    vector<int> premax(s,0);
    premax[0]=events[0][2];

    for (int i=1;i<s;i++) {
        premax[i]=max(premax[i-1],events[i][2]);
    }

    int sol=0;

    for (int i=0;i<s;i++) {
        int currValue=events[i][2];

        int left=0;
        int right=i-1;
        int index=-1;

        while (left<=right) {
            int middle=(left+right)/2;

            if (events[middle][1]<events[i][0]) {
                index=middle;
                left=middle+1;
            }
            else {
                right=middle-1;
            }
        }

        if (index!=-1) {
            sol=max(sol,currValue+premax[index]);
        }
        else {
            sol=max(sol,currValue);
        }
    }

    return sol;
}