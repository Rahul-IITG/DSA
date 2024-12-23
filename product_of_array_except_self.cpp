#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int s=nums.size();
    int count=0;
    int product=1;

    for (int i=0;i<s;i++) {
        if (nums[i]!=0) {
            product=product*nums[i];
            continue;
        }

        count++;
    }

    for (int i=0;i<s;i++) {
        if (count>1) {
            nums[i]=0;
            continue;
        }
        if (count==1) {
            nums[i] = nums[i]==0 ? product : 0;
            continue;
        }

        nums[i]=product/nums[i];
    }

    return nums;
}