#include <vector>
using namespace std;

void explore(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &vis, int &curr, int m, int n) {
    if (i-1>=0&&vis[i-1][j]==0) {
        vis[i-1][j]=1;

        if (matrix[i-1][j]<0) {
            matrix[i-1][j]=matrix[i-1][j]*-1;
            curr--;
        }
        else if (matrix[i-1][j]>0) {
            explore(i-1,j,matrix,vis,curr,m,n);
        }
    }
    if (j-1>=0&&vis[i][j-1]==0) {
        vis[i][j-1]=1;

        if (matrix[i][j-1]<0) {
            matrix[i][j-1]=matrix[i][j-1]*-1;
            curr--;
        }
        else if (matrix[i][j-1]>0) {
            explore(i,j-1,matrix,vis,curr,m,n);
        }
    }
    if (i+1<m&&vis[i+1][j]==0) {
        vis[i+1][j]=1;

        if (matrix[i+1][j]<0) {
            matrix[i+1][j]=matrix[i+1][j]*-1;
            curr--;
        }
        else if (matrix[i+1][j]>0) {
            explore(i+1,j,matrix,vis,curr,m,n);
        }
    }
    if (j+1<n&&vis[i][j+1]==0) {
        vis[i][j+1]=1;

        if (matrix[i][j+1]<0) {
            matrix[i][j+1]=matrix[i][j+1]*-1;
            curr--;
        }
        else if (matrix[i][j+1]>0) {
            explore(i,j+1,matrix,vis,curr,m,n);
        }
    }

    return;
}

int minimumPassesOfMatrix(vector<vector<int>> matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    int neg=0;

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (matrix[i][j]<0) {
                neg++;
            }
        }
    }

    if (neg==0) {
        return 0;
    }

    int count=0;

    while (true) {
        vector<vector<int>> vis(m,vector<int>(n,0));
        int curr=neg;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (matrix[i][j]>0&&vis[i][j]==0) {
                    vis[i][j]=1;
                    explore(i,j,matrix,vis,curr,m,n);
                }
            }
        }

        count++;

        if (curr==neg) {
            return -1;
        }
        if (curr==0) {
            return count;
        }

        neg=curr;
    }

    return count;
}
