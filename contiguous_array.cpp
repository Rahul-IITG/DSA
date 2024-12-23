#include <unordered_map>
#include <vector>
using namespace std;

int findMaxLength(vector<int>& nums) {
    int s=nums.size();
    unordered_map<int,int> umap;

    for (int i=0;i<s;i++) {
        if (nums[i]==0) {
            nums[i]=-1;
        }
    }

    umap[0]=-1;
    int sum=0;
    int sol=0;

    for (int i=0;i<s;i++) {
        sum=sum+nums[i];

        if (umap.find(sum)!=umap.end()) {
            sol=max(sol,i-umap[sum]);
        }
        else {
            umap[sum]=i;
        }
    }

    return sol;
}