#include <unordered_map>
#include <vector>
using namespace std;

int findLHS(vector<int>& nums) {
    int s=nums.size();

    unordered_map<int,int> umap;

    for (int i=0;i<s;i++) {
        umap[nums[i]]++;
    }

    int sol=INT_MIN;

    for (int i=0;i<s;i++) {
        if (umap[nums[i]+1]>0) {
            sol=max(sol,umap[nums[i]]+umap[nums[i]+1]);
        }
    }

    return sol == INT_MIN ? 0 : sol;
}