#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{-1,1},{1,-1}};

int countMines(vector<vector<char>>& board, pair<int,int> &click, int &m, int &n) {
    int mines=0;

    for (int i=0;i<8;i++) {
        int row=click.first+dir[i][0];
        int col=click.second+dir[i][1];

        if (row>=0&&row<m&&col>=0&&col<n) {
            if (board[row][col]=='M') {
                mines++;
            }
        }
    }
}

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int m=board.size();
    int n=board[0].size();

    if (board[click[0]][click[1]]=='M') {
        board[click[0]][click[1]]='X';
        return board;
    }

    queue<pair<int,int>> q;
    q.push({click[0],click[1]});

    while (!q.empty()) {
        auto curr=q.front();
        q.pop();
        int mines=countMines(board,curr,m,n);

        if (mines>0) {
            board[curr.first][curr.second]='0'+mines;
        }
        else {
            for (int i=0;i<8;i++) {
                int row=curr.first+dir[i][0];
                int col=curr.second+dir[i][1];

                if (row>=0&&row<m&&col>=0&&col<n) {
                    if (board[row][col]=='E') {
                        board[row][col]='B';
                        q.push({row,col});
                    }
                }
            }
        }
    }

    return board;
}