#include <unordered_map>
#include <vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int s=nums.size();
    unordered_map<int,int> umap;
    umap[0]=1;
    int sum=0;
    int count=0;

    for (int i=0;i<s;i++) {
        sum=sum+nums[i];

        if (umap.find(sum-k)!=umap.end()) {
            count=count+umap[sum-k];
        }

        umap[sum]++;
    }

    return count;
}