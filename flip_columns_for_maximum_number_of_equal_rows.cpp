#include <unordered_map>
#include <vector>
using namespace std;

int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();

    unordered_map<string,int> umap;

    for (int i=0;i<m;i++) {
        string pattern="";

        for (int j=0;j<n;j++) {
            if (matrix[i]==matrix[0]) {
                pattern.push_back('T');
            }
            else {
                pattern.push_back('F');
            }
        }

        umap[pattern]++;
    }

    int sol=0;

    for (auto itr : umap) {
        sol=max(sol,itr.second);
    }

    return sol;
}