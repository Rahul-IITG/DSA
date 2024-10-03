#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
    int s=denoms.size();
    vector<vector<int>> dp(s+1, vector<int>(n+1,-1));

    for (int i=0;i<=s;i++) {
        dp[i][0]=0;
    }
    for (int i=0;i<=n;i++) {
        dp[0][i]=-1;
    }

    dp[0][0]=0;

    for (int i=1;i<=s;i++) {
        for (int j=1;j<=n;j++) {
            if (denoms[i-1]<=j) {
                if (dp[i][j-denoms[i-1]]!=-1&&dp[i-1][j]!=-1) {
                    dp[i][j]=min(1+dp[i][j-denoms[i-1]], dp[i-1][j]);
                    continue;
                }
                if (dp[i][j-denoms[i-1]]!=-1) {
                    dp[i][j]=1+dp[i][j-denoms[i-1]];
                    continue;
                }
                if (dp[i-1][j]!=-1) {
                    dp[i][j]=dp[i-1][j];
                    continue;
                }
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[s][n];
}