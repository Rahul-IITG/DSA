#include <vector>
using namespace std;

int solve(int arr[], int i, int j, vector<vector<int>> &dp) {
    if (i>=j) {
        return 0;
    }

    if (dp[i][j]!=-1) {
        return dp[i][j];
    }

    int curr = INT_MAX;

    for (int k=i;k<j;k++) {
        int temp = solve(arr,i,k,dp) + arr[i-1]*arr[k]*arr[j] + solve(arr,k+1,j,dp);

        if (temp<curr) {
            curr=temp;
        }
    }

    dp[i][j]=curr;
    return dp[i][j];
}

int matrixMultiplication(int n, int arr[]) {
    vector<vector<int>> dp(n,vector<int>(n,-1));

    return solve(arr,1,n-1,dp);
}