vector<vector<int>> transposeMatrix(vector<vector<int>> matrix) {
    int m=matrix.size();
    int n=matrix[0].size();

    vector<vector<int>> sol(n, vector<int>(m));

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            sol[j][i]=matrix[i][j];
        }
    }

    return sol;
}