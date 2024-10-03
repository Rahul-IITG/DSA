#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
    int s=denoms.size();

    int dp[s+1][n+1];

    for (int i=0;i<=s;i++) {
        dp[i][0]=1;
    }
    for (int i=0;i<=n;i++) {
        dp[0][i]=0;
    }

    dp[0][0]=1;

    for (int i=1;i<=s;i++) {
        for (int j=1;j<=n;j++) {
            if (denoms[i-1]<=j) {
                dp[i][j]=dp[i][j-denoms[i-1]]+dp[i-1][j];
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[s][n];
}
