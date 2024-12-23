#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> dir={{0,-1},{0,1},{-1,0},{1,0}};

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();

    vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
    queue<vector<int>> q;

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (mat[i][j]==0) {
                dist[i][j]=0;
                q.push({i,j});
            }
        }
    }

    while (!q.empty()) {
        vector<int> curr=q.front();
        q.pop();

        for (int i=0;i<4;i++) {
            int x=curr[0]+dir[i][0];
            int y=curr[1]+dir[i][1];
            if (x>=0&&x<m&&y>=0&&y<n) {
                if (dist[x][y]>1+dist[curr[0]][curr[1]]) {
                    dist[x][y]>1+dist[curr[0]][curr[1]];
                    q.push({x,y});
                }
            }
        }
    }

    return dist;
}