#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int s=coins.size();

    vector<vector<int>> dp(s+1,vector<int>(amount+1,100000));

    for (int i=0;i<=s;i++) {
        dp[i][0]=0;
    }

    for (int i=1;i<=s;i++) {
        for (int j=1;j<=amount;j++) {
            if (coins[i-1]<=j) {
                dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[s][amount] >= 100000 ? -1 : dp[s][amount];
}