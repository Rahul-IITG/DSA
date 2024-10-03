#include <vector>
using namespace std;

bool isPalindrome(string str, int i, int j) {
    string str1=str.substr(i, j-i+1);
    string str2=str1;
    reverse(str2.begin(), str2.end());

    return str1==str2;
}

int solve(string str, int i, int j, vector<vector<int>> &dp) {
    if (i>=j) {
        return 0;
    }

    if (dp[i][j]!=-1) {
        return dp[i][j];
    }
    if (isPalindrome(str,i,j)) {
        dp[i][j]=0;
        return dp[i][j];
    }

    int curr=INT_MAX;

    for (int k=i;k<j;k++) {
        int temp = solve(str,i,k,dp) + 1 + solve(str,k+1,j,dp);

        if (temp<curr) {
            curr=temp;
        }
    }

    dp[i][j]=curr;
    return dp[i][j];
}

int palindromePartitioningMinCuts(string str) {
    int s=str.size();
    vector<vector<int>> dp(s,vector<int>(s,-1));

    return solve(str,0,s-1,dp);
}