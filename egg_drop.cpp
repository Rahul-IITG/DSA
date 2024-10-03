#include <vector>
using namespace std;

int solve(int n, int f, vector<vector<int>> &dp) {
    if (f==0||f==1) {
        return f;
    }
    if (n==1) {
        return f;
    }

    if (dp[n][f]!=-1) {
        return dp[n][f];
    }

    int sol=INT_MAX;

    for (int k=1;k<=f;k++) {
        int temp = 1 + max(solve(n-1,k-1,dp),solve(n,f-k,dp));

        if (temp<sol) {
            sol=temp;
        }
    }

    dp[n][f]=sol;
    return dp[n][f];
}

int eggDrop(int n, int f) {
    vector<vector<int>> dp(n+1,vector<int>(f+1,-1));
    return solve(n,f,dp);
}