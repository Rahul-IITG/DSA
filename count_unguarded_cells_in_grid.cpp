#include <vector>
using namespace std;

void explore(int &m, int &n, int row, int col, vector<vector<int>> &grid) {
    int i=1;
    int j=1;

    while (row+i<m&&(grid[row+i][col]!=2&&grid[row+i][col]!=3)) {
        grid[row+i][col]=1;
        i++;
    }
    while (col+j<n&&(grid[row][col+j]!=2&&grid[row][col+j]!=3)) {
        grid[row][col+j]=1;
        j++;
    }

    i=1;
    j=1;

    while (row-i>=0&&(grid[row-i][col]!=2&&grid[row-i][col]!=3)) {
        grid[row-i][col]=1;
        i++;
    }
    while (col-j>=0&&(grid[row][col-j]!=2&&grid[row][col-j]!=3)) {
        grid[row][col-j]=1;
        j++;
    }
}

int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<int>> grid(m,vector<int>(n,0));
    int s=guards.size();

    for (int i=0;i<s;i++) {
        grid[guards[i][0]][guards[i][1]]=2;
    }

    s=walls.size();

    for (int i=0;i<s;i++) {
        grid[walls[i][0]][walls[i][1]]=3;
    }

    s=guards.size();

    for (int i=0;i<s;i++) {
        explore(m,n,guards[i][0],guards[i][1],grid);
    }

    int sol=0;

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (grid[i][j]==0) {
                sol++;
            }
        }
    }

    return sol;
}