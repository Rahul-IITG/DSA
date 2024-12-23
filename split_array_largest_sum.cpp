#include <vector>
using namespace std;

int recur(vector<int> &presum, int index, int k, vector<vector<int>> &dp, int &s) {
    if (dp[index][k]!=-1) {
        return dp[index][k];
    }

    if (k==1) {
        dp[index][k]=presum[s]-presum[index];
        return presum[s]-presum[index];
    }

    int minSum=INT_MAX;

    for (int i=index;i<=s-k;i++) {
        int firstSplit=presum[i+1]-presum[index];
        int secondSplit=recur(presum,i+1,k-1,dp,s);

        minSum=min(minSum,min(firstSplit,secondSplit));
    }

    dp[index][k]=minSum;
    return dp[index][k];
}

int splitArray(vector<int>& nums, int k) {
    int s=nums.size();
    vector<vector<int>> dp(s+1,vector<int>(k+1,-1));
    vector<int> presum(s+1,0);

    for (int i=0;i<s;i++) {
        presum[i+1]=presum[i]+nums[i];
    }

    return recur(presum,0,k,dp,s);
}