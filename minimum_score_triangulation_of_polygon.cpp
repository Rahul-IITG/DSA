#include <vector>
using namespace std;

int solve(vector<int> values, int i, int j, vector<vector<int>> &dp) {
    if (dp[i][j]!=-1) {
        return dp[i][j];
    }

    int sol=INT_MAX;

    for (int k=i+1;k<j;k++) {
        int temp = solve(values,i,k,dp) + values[i]*values[k]*values[j] + solve(values,k,j,dp);

        if (temp<sol) {
            sol=temp;
        }
    }

    if (sol==INT_MAX) {
        dp[i][j]=0;
        return dp[i][j];
    }

    dp[i][j]=sol;
    return dp[i][j];
}

int minScoreTriangulation(vector<int>& values) {
    int s=values.size();
    vector<vector<int>> dp(s,vector<int>(s,-1));
    return solve(values,0,s-1,dp);
}