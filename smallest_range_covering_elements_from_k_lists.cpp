#include <queue>
#include <vector>
using namespace std;

vector<int> smallestRange(vector<vector<int>>& nums) {
    int s=nums.size();
    typedef pair<int,pair<int,int>> ppi;
    priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
    int maxRange=INT_MIN;

    for (int i=0;i<s;i++) {
        pq.push({nums[i][0],{i,0}});
        maxRange=max(maxRange,nums[i][0]);
    }

    int start=0;
    int end=INT_MAX;
    int minRange;

    while (pq.size()==s) {
        ppi curr=pq.top();
        pq.pop();

        minRange=curr.first;
        int row=curr.second.first;
        int col=curr.second.second;

        if (maxRange-minRange<end-start) {
            start=minRange;
            end=maxRange;
        }

        if (col+1<nums[row].size()) {
            pq.push({nums[row][col+1],{row,col+1}});
            maxRange=max(maxRange,nums[row][col+1]);
        }
    }

    return {start,end};
}