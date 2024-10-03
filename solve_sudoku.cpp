#include <vector>
using namespace std;

bool checkRow(int row, int col, int k, vector<vector<int>> board) {
    for (int i=0;i<9;i++) {
        if (board[row][i]==k) {
            return false;
        }
    }

    return true;
}

bool checkCol(int row, int col, int k, vector<vector<int>> board) {
    for (int i=0;i<9;i++) {
        if (board[i][col]==k) {
            return false;
        }
    }

    return true;
}

bool checkBox(int row, int col, int k, vector<vector<int>> board) {
    row=(row/3)*3;
    col=(col/3)*3;

    for (int i=row;i<row+3;i++) {
        for (int j=col;j<col+3;j++) {
            if (board[i][j]==k) {
                return false;
            }
        }
    }

    return true;
}

bool isSafe(int row, int col, int k, vector<vector<int>> board) {
    return checkRow(row,col,k,board) && checkCol(row,col,k,board) && checkBox(row,col,k,board);
}

bool fillSudoku(vector<vector<int>> &board) {
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            if (board[i][j]!=0) {
                continue;
            }

            for (int k=1;k<=9;k++) {
                if (isSafe(i,j,k,board)) {
                    board[i][j]=k;

                    if (fillSudoku(board)) {
                        return true;
                    }

                    board[i][j]=0;
                }
            }

            return false;
        }
    }

    return true;
}

vector<vector<int>> solveSudoku(vector<vector<int>> board) {
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            if (board[i][j]!=0) {
                continue;
            }

            for (int k=1;k<=9;k++) {
                if (isSafe(i,j,k,board)) {
                    board[i][j]=k;

                    if (fillSudoku(board)) {
                        return board;
                    }
                }
            }
        }
    }

    return board;
}