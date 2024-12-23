#include <vector>
using namespace std;

vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};

void explore(int row, int col, int &m, int &n, vector<vector<char>> &grid, vector<vector<int>> &vis) {
    for (int i=0;i<4;i++) {
        int nr=row+dir[i][0];
        int nc=col+dir[i][1];

        if (nr>=0&&nr<m&&nc>=0&&nc<n) {
            if (vis[nr][nc]==0&&grid[nr][nc]=='1') {
                vis[nr][nc]=1;
                explore(nr,nc,m,n,grid,vis);
            }
        }
    }

    return;
}

int numIslands(vector<vector<char>>& grid) {
    int m=grid.size();
    int n=grid[0].size();

    vector<vector<int>> vis(m,vector<int>(n,0));
    int count=0;

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (vis[i][j]==0&&grid[i][j]=='1') {
                vis[i][j]=1;
                explore(i,j,m,n,grid,vis);
                count++;
            }
        }
    }

    return count;
}