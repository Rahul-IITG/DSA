#include <unordered_map>
#include <vector>
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
    int s=nums.size();
    sort(nums.begin(),nums.end());
    int sol=0;
    int curr=0;
    int target;
    int left=0;

    for (int right=0;right<s;right++) {
        target=nums[right];
        curr=curr+target;

        while ((right-left+1)*target-curr>k) {
            curr=curr-nums[left];
            left++;
        }

        sol=max(sol,right-left+1);
    }

    return sol;
}