#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};

int orangesRotting(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();

    vector<vector<int>> time(m,vector<int>(n,INT_MAX-1));
    queue<pair<int,int>> q;

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (grid[i][j]==2) {
                time[i][j]=0;
                q.push({i,j});
            }
        }
    }

    int maxTime=INT_MIN;

    while (!q.empty()) {
        auto curr=q.front();
        q.pop();

        for (int i=0;i<4;i++) {
            int row=curr.first+dir[i][0];
            int col=curr.second+dir[i][1];

            if (row>=0&&row<m&&col>=0&&col<n) {
                if (grid[row][col]==1&&time[row][col]>time[curr.first][curr.second]+1) {
                    time[row][col]=time[curr.first][curr.second]+1;
                    maxTime=max(maxTime,time[row][col]);
                    q.push({row,col});
                }
            }
        }
    }

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (time[i][j]==INT_MIN-1) {
                return -1;
            }
        }
    }

    return maxTime;
}