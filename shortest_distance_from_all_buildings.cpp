#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};

void bfs(int row, int col, int buildings, vector<vector<int>> &grid, vector<vector<int>> &dis, vector<vector<int>> &reached, int &m, int &n) {
    queue<vector<int>> q;
    vector<vector<int>> vis(m,vector<int>(n,0));
    q.push({row,col,0});

    while (!q.empty()) {
        auto curr=q.front();
        q.pop();
        int i=curr[0];
        int j=curr[1];
        int dist=curr[2];

        for (int k=0;k<4;k++) {
            int newRow=i+dir[k][0];
            int newCol=j+dir[k][1];

            if (newRow>=0&&newRow<m&&newCol>=0&&newCol<n&&vis[newRow][newCol]==0&&grid[newRow][newCol]==0) {
                dis[newRow][newCol]=dis[newRow][newCol]+1+dist;
                vis[newRow][newCol]=1;
                reached[newRow][newCol]++;
                q.push({newRow,newCol,dist+1});
            }
        }
    }
}

int shortestDistance(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();

    vector<vector<int>> dis(m,vector<int>(n,0));
    vector<vector<int>> reached(m, vector<int>(n,0));
    int buildings=0;

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (grid[i][j]==1) {
                buildings++;
                bfs(i,j,buildings,grid,dis,reached,m,n);
            }
        }
    }

    int sol=INT_MAX;

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (grid[i][j]==0&&reached[i][j]==buildings) {
                sol=min(sol,dis[i][j]);
            }
        }
    }

    return sol == INT_MAX ? -1 : sol;
}