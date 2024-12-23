#include <vector>
using namespace std;

void permutate(int start, int cs, int size, int s, vector<int> &nums, vector<int> curr, vector<vector<int>> &sol) {
    if (cs==size) {
        sol.push_back(curr);
        return;
    }

    for (int i=start;i<s;i++) {
        curr.push_back(nums[i]);
        permutate(i+1,cs+1,size,s,nums,curr,sol);
        curr.pop_back();
    }

    return;
}

vector<vector<int>> subsets(vector<int>& nums) {
    int s=nums.size();
    vector<vector<int>> sol;
    vector<int> curr;

    for (int i=0;i<=s;i++) {
        permutate(0,0,i,s,nums,curr,sol);
    }

    return sol;
}