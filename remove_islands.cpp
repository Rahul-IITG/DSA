#include <vector>
using namespace std;

void explore(int row, int col, vector<vector<int>> matrix, vector<vector<int>> &vis, vector<vector<bool>> &island, int m, int n) {
    int i,j;

    if (row-1>=0&&matrix[row-1][col]==1) {
        i=row-1;
        j=col;
        if (vis[i][j]==-1) {
            vis[i][j]=1;
            island[i][j]=false;
            explore(i,j,matrix,vis,island,m,n);
        }
    }
    if (col-1>=0&&matrix[row][col-1]==1) {
        i=row;
        j=col-1;
        if (vis[i][j]==-1) {
            vis[i][j]=1;
            island[i][j]=false;
            explore(i,j,matrix,vis,island,m,n);
        }
    }
    if (row+1<m&&matrix[row+1][col]==1) {
        i=row+1;
        j=col;
        if (vis[i][j]==-1) {
            vis[i][j]=1;
            island[i][j]=false;
            explore(i,j,matrix,vis,island,m,n);
        }
    }
    if (col+1<n&&matrix[row][col+1]==1) {
        i=row;
        j=col+1;
        if (vis[i][j]==-1) {
            vis[i][j]=1;
            island[i][j]=false;
            explore(i,j,matrix,vis,island,m,n);
        }
    }

    return;
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
    int m=matrix.size();
    int n=matrix[0].size();

    vector<vector<int>> vis(m,vector<int>(n,-1));
    vector<vector<bool>> island(m,vector<bool>(n,true));

    for (int i=0;i<m;i++) {
        if (vis[i][0]==-1&&matrix[i][0]==1) {
            vis[i][0]=1;
            island[i][0]=false;
            explore(i,0,matrix,vis,island,m,n);
        }
        if (vis[i][n-1]==-1&&matrix[i][n-1]==1) {
            vis[i][n-1]=1;
            island[i][n-1]=false;
            explore(i,n-1,matrix,vis,island,m,n);
        }
    }

    for (int i=0;i<n;i++) {
        if (vis[0][i]==-1&&matrix[0][i]==1) {
            vis[0][i]=1;
            island[0][i]=false;
            explore(0,i,matrix,vis,island,m,n);
        }
        if (vis[m-1][i]==-1&&matrix[m-1][i]==1) {
            vis[m-1][i]=1;
            island[m-1][i]=false;
            explore(m-1,i,matrix,vis,island,m,n);
        }
    }

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (matrix[i][j]==1&&island[i][j]==true) {
                matrix[i][j]=0;
            }
        }
    }

    return matrix;
}