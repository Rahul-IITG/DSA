#include <vector>
using namespace std;

bool check(int s, vector<int> &diff, vector<int> &nums) {
    int currDiff=0;

    for (int i=0;i<s;i++) {
        currDiff+=diff[i];
        nums[i]=max(0,nums[i]-currDiff);

        if (nums[i]>0) {
            return false;
        }
    }

    return true;
}

int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int s=nums.size();
    int q=queries.size();

    vector<int> diff(s+1,0);

    for (int i=0;i<q;i++) {
        diff[queries[i][0]]+=-queries[i][2];

        if (queries[i][1]+1<s) {
            diff[queries[i][1]]+=queries[i][2];
        }

        if (check(s,diff,nums)) {
            return i+1;
        }
    }

    return -1;
}