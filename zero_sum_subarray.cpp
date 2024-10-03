#include <unordered_map>
#include <vector>
using namespace std;

bool zeroSumSubarray(vector<int> nums) {
    int s=nums.size();
    unordered_map<int,int> umap;
    int sum=0;

    for (int i=0;i<s;i++) {
        if (umap[sum+nums[i]]!=0) {
            return true;
        }

        umap[sum+nums[i]]++;
        sum=sum+nums[i];
    }

    return false;
}
