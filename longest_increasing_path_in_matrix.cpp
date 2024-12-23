#include <vector>
using namespace std;

vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};

int dfs(int i, int j, int m, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    if (dp[i][j]!=-1) {
        return dp[i][j];
    }

    int maxx=1;

    for (int k=0;k<4;k++) {
        int row=i+dir[k][0];
        int col=j+dir[k][1];

        if (row>=0&&row<m&&col>=0&&col<n&&matrix[i][j]<matrix[row][col]) {
            maxx=max(maxx,1+dfs(row,col,m,n,matrix,dp));
        }
    }

    dp[i][j]=maxx;
    return dp[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();

    vector<vector<int>> dp(m,vector<int>(n,-1));
    int maxx=0;

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            maxx=max(maxx,dfs(i,j,m,n,matrix,dp));
        }
    }

    return maxx;
}