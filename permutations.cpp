#include <vector>
using namespace std;

void permutate(int s, vector<int> array, vector<int> &vis, vector<vector<int>> &sol, vector<int> curr, int k) {
    if (k==s) {
        sol.push_back(curr);
        return;
    }

    for (int i=0;i<s;i++) {
        if (vis[i]==0) {
            vis[i]=1;
            vector<int> cc=curr;
            cc.push_back(array[i]);
            permutate(s,array,vis,sol,cc,k+1);
            vis[i]=0;
        }
    }

    return;
}

vector<vector<int>> getPermutations(vector<int> array) {
    int s=array.size();

    vector<int> vis(s,0);
    vector<vector<int>> sol;

    for (int i=0;i<s;i++) {
        vis[i]=1;
        vector<int> curr;
        curr.push_back(array[i]);
        permutate(s,array,vis,sol,curr,1);
        vis[i]=0;
    }

    return sol;
}
