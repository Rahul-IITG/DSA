#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int s=nums.size();

    int curr=0;
    int sum=INT_MIN;
    int left=0;
    int right=0;

    while (right<s) {
        curr=curr+nums[right];

        if (right-left+1==k) {
            sum=max(sum,curr);
            curr=curr-nums[left];
            left++;
        }

        right++;
    }

    double average=sum/k;
    return average;
}