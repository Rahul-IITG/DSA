#include <unordered_map>
#include <vector>
using namespace std;

int getLargestOutlier(vector<int>& nums) {
    int s=nums.size();
    int sum=0;
    unordered_map<int,int> umap;

    for (int i=0;i<s;i++) {
        sum=sum+nums[i];
        umap[nums[i]]++;
    }

    int sol=INT_MIN;
    int curr;

    for (int i=0;i<s;i++) {
        if (sum-nums[i]%2!=0) {
            continue;
        }

        umap[nums[i]]--;

        if (umap[(sum-nums[i])/2]!=0) {
            sol=max(sol,nums[i]);
        }

        umap[nums[i]]++;
    }

    return sol;
}