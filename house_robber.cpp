#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    int s=nums.size();
    int sol=INT_MIN;

    if (s==1) {
        return nums[0];
    }
    if (s==2) {
        return max(nums[0],nums[1]);
    }
    if (s==3) {
        return max(nums[0]+nums[2],nums[1]);
    }

    nums[2]=nums[0]+nums[2];
    sol=max(sol,nums[2]);

    for (int i=3;i<s;i++) {
        nums[i]=nums[i]+max(nums[i-2],nums[i-3]);
        sol=max(nums[i],sol);
    }

    return sol;
}