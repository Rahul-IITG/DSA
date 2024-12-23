#include <vector>
using namespace std;

int maximumBeauty(vector<int>& nums, int k) {
    int s=nums.size();
    int maxRange=INT_MIN;

    for (int i=0;i<s;i++) {
        maxRange=max(maxRange,nums[i]);
    }

    vector<int> range(maxRange+k+1,0);

    for (int i=0;i<s;i++) {
        int left=max(0,nums[i]-k);
        int right=min(nums[i]+k,maxRange)+1;

        range[left]++;
        range[right]--;
    }

    int sol=0;

    for (int i=1;i<range.size();i++) {
        range[i]=range[i]+range[i-1];

        if (range[i]>sol) {
            sol=range[i];
        }
    }

    return sol;
}