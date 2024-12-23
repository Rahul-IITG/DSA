#include <vector>
using namespace std;

void permutate(int &s, vector<int> &candidates, vector<int> curr, vector<vector<int>> &sol, int sum, int &target, int start) {
    if (sum==target) {
        sol.push_back(curr);
        return;
    }

    for (int i=start;i<s;i++) {
        if (sum+candidates[i]<=target) {
            curr.push_back(candidates[i]);
            permutate(s,candidates,curr,sol,sum+candidates[i],target,i);
            curr.pop_back();
        }
    }

    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int s=candidates.size();
    vector<int> curr;
    vector<vector<int>> sol;
    permutate(s,candidates,curr,sol,0,target,0);

    return sol;
}