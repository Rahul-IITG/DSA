#include <vector>

using namespace std;

int solve(vector<int> nums, int i, int j, int s, vector<vector<int>> dp) {
    if (i>j) {
        return 0;
    }

    if (dp[i][j]!=-1) {
        return dp[i][j];
    }

    int sol=INT_MIN;

    for (int k=i;k<=j;k++) {
        int temp=nums[k];

        if (i-1>0) {
            temp=temp*nums[i-1];
        }
        if (j+1<s) {
            temp=temp*nums[j+1];
        }

        int curr = solve(nums,i,k-1,s,dp) + temp + solve(nums,k+1,j,s,dp);
        sol=max(sol,curr);
    }

    dp[i][j]=sol;
    return sol;
}

int maxCoins(vector<int>& nums) {
    int s=nums.size();
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    vector<vector<int>> dp(s+2,vector<int>(s+2,-1));
    return solve(nums,1,s,s+2,dp);
}
