#include <vector>

using namespace std;

bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int s=nums.size();
    int q=queries.size();
    vector<int> diff(s+1,0);

    for (int i=0;i<q;i++) {
        diff[queries[i][0]]+=-1;

        if (queries[i][1]+1<s) {
            diff[queries[i][1]+1]+=1;
        }
    }

    int currDiff=0;

    for (int i=0;i<s;i++) {
        currDiff+=diff[i];
        nums[i]+=currDiff;
    }

    for (int i=0;i<s;i++) {
        if (nums[i]>0) {
            return false;
        }
    }

    return true;
}
