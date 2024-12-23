#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int s=nums.size();
    unordered_map<int,int> umap;
    priority_queue<int> pq;
    int i=0;
    vector<int> sol;

    while (i<s) {
        if (pq.size()<k) {
            pq.push(nums[i]);
            umap[nums[i]]++;

            if (pq.size()==k) {
                sol.push_back(pq.top());
            }
        }
        else {
            umap[nums[i-k]]--;
            pq.push(nums[i]);
            umap[nums[i]]++;

            while (!pq.empty()&&umap[pq.top()]==0) {
                pq.pop();
            }

            sol.push_back(pq.top());
        }

        i++;
    }

    return sol;
}