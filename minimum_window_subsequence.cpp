#include <string>
#include <vector>
using namespace std;

string minWindow(string s1, string s2) {
    int m=s1.size();
    int n=s2.size();

    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

    for (int i=0;i<=m;i++) {
        dp[i][0]=0;
    }
    for (int i=0;i<=n;i++) {
        dp[0][i]=-1;
    }

    dp[0][0]=0;
    int sol=INT_MAX;
    int end=0;

    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (s1[i-1]==s2[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]=dp[i-1][j]+1;
            }
        }

        if (sol>dp[i][n]) {
            sol=dp[i][n];
            end=i;
        }
    }

    return sol>m ? -1 : s1.substr(end-sol,sol);
}