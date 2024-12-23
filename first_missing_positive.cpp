#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int s=nums.size();

    for (int i=0;i<s;i++) {
        if (nums[i]>0&&nums[i]<=s&&nums[i]!=nums[nums[i]-1]) {
            swap(nums[i],nums[nums[i]-1]);
        }
    }

    for (int i=0;i<s;i++) {
        if (nums[i]!=i+1) {
            return i+1;
        }
    }

    return s+1;
}