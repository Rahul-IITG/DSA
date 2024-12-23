#include <unordered_map>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int s=nums.size();

    if (k==0) {
        return false;
    }

    unordered_map<int,int> umap;

    int left=0;
    int right=0;

    while (right<s) {
        if (left==right) {
            umap[nums[right]]++;
            right++;
            continue;
        }

        if (umap[nums[right]]>0) {
            return true;
        }

        umap[nums[right]]++;

        if (right-left+1==k) {
            umap[nums[left]]--;
            left++;
        }

        right++;
    }

    return false;
}