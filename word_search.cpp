#include <vector>
using namespace std;

vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};

bool explore(int row, int col, int &m, int &n, int index, int &s, string &word, vector<vector<char>> &board, vector<vector<int>> &vis) {
    if (index==s) {
        return true;
    }

    int nr;
    int nc;

    for (int i=0;i<4;i++) {
        nr=row+dir[i][0];
        nc=col+dir[i][1];

        if (nr>=0&&nr<m&&nc>=0&&nc<n) {
            if (board[nr][nc]==word[index]&&vis[nr][nc]==0) {
                vis[nr][nc]=1;

                if (explore(nr,nc,m,n,index+1,s,word,board,vis)) {
                    return true;
                }

                vis[nr][nc]=0;
            }
        }
    }

    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int m=board.size();
    int n=board[0].size();

    int s=word.size();
    vector<vector<int>> vis(m,vector<int>(n,0));

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (board[i][j]==word[0]&&vis[i][j]==0) {
                vis[i][j]=1;

                if (explore(i,j,m,n,1,s,word,board,vis)) {
                    return true;
                }

                vis[i][j]=0;
            }
        }
    }

    return false;
}