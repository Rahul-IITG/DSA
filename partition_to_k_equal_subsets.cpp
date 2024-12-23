#include <vector>
using namespace std;

bool backtrack(int &s, int index, vector<int> &nums, int &k, vector<int> &subset, int &sum) {
    if (index==s) {
        for (auto set : subset) {
            if (set!=sum) {
                return false;
            }
        }

        return true;
    }

    for (int i=0;i<k;i++) {
        if (subset[i]+nums[index]>sum) {
            continue;
        }

        subset[i]=subset[i]+nums[index];

        if (backtrack(s,index+1,nums,k,subset,sum)) {
            return true;
        }

        subset[i]=subset[i]-nums[index];
    }

    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int s=nums.size();
    int sum=0;

    for (auto curr : nums) {
        sum=sum+curr;
    }

    if (sum%k!=0) {
        return false;
    }

    sum=sum/k;
    vector<int> subset(k,0);

    return backtrack(s,0,nums,k,subset,sum);
}