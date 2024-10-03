#include <vector>
using namespace std;

int solve(vector<int> array) {
    int s=array.size();
    int sum=0;

    for (int i=0;i<s;i++) {
        sum=sum+array[i];
    }

    bool dp[s+1][sum+1];

    for (int i=0;i<=s;i++) {
        dp[i][0]=true;
    }
    for (int i=0;i<=sum;i++) {
        dp[0][i]=false;
    }

    dp[0][0]=true;

    for (int i=1;i<=s;i++) {
        for (int j=1;j<=sum;j++) {
            if (array[i-1]<=j) {
                dp[i][j] = dp[i-1][j-array[i-1]] || dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int ans=0;

    for (int i=0;i<=sum/2;i++) {
        if (dp[s][i]) {
            ans=sum-2*i;
        }
    }

    return ans;
}
