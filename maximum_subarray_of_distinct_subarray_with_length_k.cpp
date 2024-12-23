#include <deque>
#include <unordered_map>
#include <vector>
using namespace std;

long long maximumSubarraySum(vector<int>& nums, int k) {
    int s=nums.size();

    int left=0;
    int right=0;
    int sum=0;
    int sol=0;
    unordered_map<int,int> umap;

    while (right<s) {
        int last=umap.count(nums[right]) ? umap[nums[right]] : -1;

        while (left<=last||(right-left+1)>k) {
            sum=sum-nums[left];
            left++;
        }

        umap[nums[right]]=right;

        if (right-left+1==k) {
            sol=max(sol,sum);
        }

        right++;
    }

    return sol;
}