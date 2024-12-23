#include <vector>
using namespace std;

int solve(vector<int> &ranges, int i, int j, int n, vector<vector<int>> &dp) {
    if (i<0||j>n) {
        return 0;
    }
    if (i>=j) {
        return 0;
    }

    if (dp[i][j]!=INT_MAX) {
        return dp[i][j];
    }

    int sol=INT_MAX;

    for (int k=i;k<=j;k++) {
        if (ranges[k]==0) {
            continue;
        }
        int left = solve(ranges,i,k-ranges[k],n,dp);
        int right = solve(ranges,k+ranges[k],j,n,dp);

        if (left==INT_MAX||right==INT_MAX) {
            continue;
        }

        int temp = left+1+right;

        sol=min(sol,temp);
    }

    dp[i][j]=sol;
    return sol;
}

int minTaps(int n, vector<int>& ranges) {
    vector<int> tap(n+1,n+2);
    tap[0]=0;

    for (int i=0;i<=n;i++) {
        int leftMost = max(i-ranges[i],0);
        int rightMost = min(i+ranges[i],n);

        for (int j=leftMost;j<=rightMost;j++) {
            tap[j] = min(tap[j],tap[leftMost]+1);
        }
    }

    return tap[n] == n+2 ? -1 : tap[n];
}