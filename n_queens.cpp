#include <unordered_set>
#include <vector>
using namespace std;

bool isRowSafe(int row, int col, int n, vector<vector<string>> &board) {
    for (int i=0;i<n;i++) {
        if (board[row][i]!="") {
            return false;
        }
    }

    return true;
}

bool isColSafe(int row, int col, int n, vector<vector<string>> &board) {
    for (int i=0;i<n;i++) {
        if (board[i][col]!="") {
            return false;
        }
    }

    return true;
}

bool isDiaSafe(int row, int col, int n, vector<vector<string>> &board) {
    int cr=row;
    int cc=col;

    while (cr>=0&&cc>=0) {
        if (board[cr][cc]!="") {
            return false;
        }

        cr--;
        cc--;
    }

    cr=row;
    cc=col;

    while (cr>=0&&cc<n) {
        if (board[cr][cc]!="") {
            return false;
        }

        cr--;
        cc++;
    }

    cr=row;
    cc=col;

    while (cr<n&&cc>=0) {
        if (board[cr][cc]!="") {
            return false;
        }

        cr++;
        cc--;
    }

    cr=row;
    cc=col;

    while (cr<n&&cc<n) {
        if (board[cr][cc]!="") {
            return false;
        }

        cr++;
        cc++;
    }

    return true;
}

bool isSafe(int row, int col, int n, vector<vector<string>> &board) {
    return isRowSafe(row,col,n,board) && isColSafe(row,col,n,board) && isDiaSafe(row,col,n,board);
}

bool solve(int count, int n, vector<vector<string>> &board) {
    if (count==n) {
        return true;
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (board[i][j]!="") {
                continue;
            }

            if (isSafe(i,j,n,board)) {
                board[i][j]="Q";

                if (solve(count+1,n,board)) {
                    return true;
                }

                board[i][j]="";
            }
        }
    }

    return false;
}

void solve(int row, unordered_set<int> &cols, unordered_set<int> &diap, unordered_set<int> &dias, int &n, int &count) {
    if (row==n) {
        count++;
        return;
    }

    for (int j=0;j<n;j++) {
        if (cols.count(j)||diap.count(row-j)||dias.count(row+j)) {
            continue;
        }

        cols.insert(j);
        diap.insert(row-j);
        dias.insert(row+j);
        solve(row+1,cols,diap,dias,n,count);
        cols.erase(j);
        diap.erase(row-j);
        dias.erase(row+j);
    }

    return;
}

int totalNQueens(int n) {
    int count=0;
    unordered_set<int> cols;
    unordered_set<int> diap;
    unordered_set<int> dias;
    solve(0,cols,diap,dias,n,count);
    return count;
}

void solve(int row, unordered_set<int> &cols, unordered_set<int> &diap, unordered_set<int> &dias, int &n, vector<vector<string>> &sol, vector<string> &board) {
    if (row==n) {
        sol.push_back(board);
        return;
    }

    for (int j=0;j<n;j++) {
        if (cols.count(j)||diap.count(row-j)||dias.count(row+j)) {
            continue;
        }

        board[row][j]='Q';
        cols.insert(j);
        diap.insert(row-j);
        dias.insert(row+j);
        solve(row+1,cols,diap,dias,n,sol,board);
        cols.erase(j);
        diap.erase(row-j);
        dias.erase(row+j);
        board[row][j]='.';
    }

    return;
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> sol;
    vector<string> board(n,string(n,'.'));
    unordered_set<int> cols;
    unordered_set<int> diap;
    unordered_set<int> dias;
    solve(0,cols,diap,dias,n,sol,board);
    return sol;
}

/*vector<vector<string>> convert(int n, vector<vector<string>> &board) {
    vector<vector<string>> sol;
    string curr="";

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (board[i][j]=="") {
                curr.push_back('.');
            }
            else {
                curr.push_back('Q');
            }
        }

        sol.push_back(curr);
        curr="";
    }
}*/
