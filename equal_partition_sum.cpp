#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int s=nums.size();
    int sum=0;

    for (int i=0;i<s;i++) {
        sum=sum+nums[i];
    }

    if (sum%2!=0) {
        return false;
    }

    sum=sum/2;

    bool dp[s+1][sum+1];

    for (int i=0;i<=s;i++) {
        dp[i][0]=true;
    }
    for (int i=0;i<=sum;i++) {
        dp[0][i]=false;
    }

    dp[0][0]=true;

    for (int i=0;i<=s;i++) {
        for (int j=0;j<=sum;j++) {
            if (nums[i-1]<=j) {
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[s][sum];
}


