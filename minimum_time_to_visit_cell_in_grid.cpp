#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};

int minimumTime(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();

    if (grid[0][1] > 1 && grid[1][0] > 1) {
        return -1;
    }

    vector<vector<int>> vis(m,vector<int>(n,0));
    priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
    pq.push({0,0,0});

    while (!pq.empty()) {
        auto curr=pq.top();
        int r=curr[1];
        int c=curr[2];
        int t=curr[0];
        pq.pop();

        if (r==m-1&&c==n-1) {
            return t;
        }

        if (vis[r][c]==1) {
            continue;
        }

        vis[r][r]=1;

        for (int i=0;i<4;i++) {
            int row=r+dir[i][0];
            int col=c+dir[i][1];

            if (row>=0&&row<m&&col>=0&&col<n&&vis[row][col]==0) {
                int waitTime=((grid[row][col]-t)%2 == 0) ? 1 : 0;
                int nextTime=max(grid[row][col]+waitTime,t+1);
                pq.push({row,col,nextTime});
            }
        }
    }

    return -1;
}