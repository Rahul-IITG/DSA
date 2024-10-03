#include <vector>
using namespace std;

void traverse(int i, int j, vector<vector<int>> &vis, vector<vector<int>> matrix, int &count, int m, int n) {
    if (i-1>=0) {
        if (matrix[i-1][j]==1 && vis[i-1][j]==0) {
            count++;
            vis[i-1][j]=1;
            traverse(i-1,j,vis,matrix,count,m,n);
        }
    }
    if (i+1<m) {
        if (matrix[i+1][j]==1 && vis[i+1][j]==0) {
            count++;
            vis[i+1][j]=1;
            traverse(i+1,j,vis,matrix,count,m,n);
        }
    }
    if (j-1>=0) {
        if (matrix[i][j-1]==1 && vis[i][j-1]==0) {
            count++;
            vis[i][j-1]=1;
            traverse(i,j-1,vis,matrix,count,m,n);
        }
    }
    if (j+1<n) {
        if (matrix[i][j+1]==1 && vis[i][j+1]==0) {
            count++;
            vis[i][j+1]=1;
            traverse(i,j+1,vis,matrix,count,m,n);
        }
    }

    return;
}

vector<int> riverSizes(vector<vector<int>> matrix) {
    int m=matrix.size();
    int n=matrix[0].size();

    vector<vector<int>> vis(m,vector<int>(n,0));
    vector<int> sol;

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (matrix[i][j]==1 && vis[i][j]==0) {
                int count=1;
                vis[i][j]=1;
                traverse(i,j,vis,matrix,count,m,n);
                sol.push_back(count);
            }
        }
    }

    return sol;
}