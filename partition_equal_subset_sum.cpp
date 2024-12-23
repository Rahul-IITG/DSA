#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int s=nums.size();
    int sum=0;

    for (int i=0;i<s;i++) {
        sum+=nums[i];
    }

    if (sum%2!=0) {
        return false;
    }

    sum=sum/2;

    vector<vector<bool>> dp(s+1,vector<bool>(sum+1,false));

    for (int i=0;i<=s;i++) {
        dp[i][0]=true;
    }

    for (int i=1;i<=s;i++) {
        for (int j=1;j<=sum;j++) {
            if (j>=nums[i-1]) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[s][sum];
}