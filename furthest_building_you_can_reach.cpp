#include <queue>
#include <vector>
using namespace std;

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int s=heights.size();
    int sol=0;

    priority_queue<int,vector<int>,greater<vector<int>>> pq;

    for (int i=0;i<s-1;i++) {
        if (heights[i]>=heights[i+1]) {
            continue;
        }

        pq.push(heights[i+1]-heights[i]);

        if (pq.size()<=ladders) {
            continue;
        }

        int minClimb=pq.top();
        pq.pop();

        bricks=bricks-minClimb;

        if (bricks<0) {
            return i;
        }
    }

    return s-1;
}