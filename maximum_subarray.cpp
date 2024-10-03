#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int s=nums.size();
    int sol=nums[0];

    for (int i=1;i<s;i++) {
        if (nums[i]<nums[i]+nums[i-1]) {
            nums[i]=nums[i]+nums[i-1];
        }

        sol=max(sol,nums[i]);
    }

    return sol;
}