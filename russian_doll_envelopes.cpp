#include <vector>
using namespace std;

bool comp_func(vector<int> &a, vector<int> &b) {
    if (a[0]==b[0]) {
        return a[1]>b[1];
    }

    return a[0]<b[0];
}

int binarySearch(vector<int> &sol, int &num) {
    int left=0;
    int right=sol.size();

    while (left<right) {
        int middle=(left+right)/2;

        if (sol[middle]==num) {
            return middle;
        }

        if (sol[middle]<num) {
            left=middle+1;
        }
        else {
            right=middle;
        }
    }

    return left;
}

int lengthOfLIS(vector<int>& nums) {
    int s=nums.size();
    vector<int> sol;
    sol.push_back(nums[0]);

    for (int i=1;i<s;i++) {
        if (sol[sol.size()-1]<nums[i]) {
            sol.push_back(nums[i]);
        }
        else {
            int index=binarySearch(sol,nums[i]);
            sol[index]=nums[i];
        }
    }

    return sol.size();
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(),envelopes.end(),comp_func);
    vector<int> nums;
    int s=envelopes.size();

    for (int i=0;i<s;i++) {
        nums.push_back(envelopes[i][1]);
    }

    return lengthOfLIS(nums);
}