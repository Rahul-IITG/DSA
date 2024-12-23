#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int s=nums.size();
    int max=nums[0];

    for (int i=1;i<s;i++) {
        if (nums[i]<nums[i]+nums[i-1]) {
            nums[i]=nums[i]+nums[i-1];
        }

        max=max(max,nums[i]);
    }

    return max;
}