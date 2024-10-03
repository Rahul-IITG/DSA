#include <vector>
using namespace std;

void search(int row, int left, int right, vector<int> &sol, vector<vector<int>> matrix, int target) {
    int middle;

    while (left<right) {
        middle=(left+right)/2;

        if (matrix[row][middle]==target) {
            sol.push_back(row);
            sol.push_back(middle);
            return;
        }

        if (target<matrix[row][middle]) {
            right=middle;
            continue;
        }
        if (target>matrix[row][middle]) {
            left=middle+1;
            continue;
        }
    }

    if (left==right&&matrix[row][middle]==target) {
        sol.push_back(row);
        sol.push_back(middle);
        return;
    }
}

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
    int m=matrix.size();
    int n=matrix[0].size();
    vector<int> sol;

    for (int i=0;i<m;i++) {
        if (matrix[i][n-1]<target) {
            continue;
        }
        if (matrix[i][n-1]>=target) {
            search(i,0,n-1,sol,matrix,target);
            break;
        }
    }

    return sol;
}
