#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int s=nums.size();
    unordered_map<int,int> umap;
    sort(nums.begin(),nums.end());

    for (int i=0;i<s;i++) {
        umap[nums[i]]++;
    }

    vector<vector<int>> sol;
    vector<int> curr(3);
    set<vector<int>> smap;

    for (int i=0;i<s;i++) {
        umap[nums[i]]--;

        for (int j=i+1;j<s;j++) {
            umap[nums[j]]--;

            if (umap[-1*(nums[i]+nums[j])]!=0) {
                curr[0]=nums[i];
                curr[1]=nums[j];
                curr[2]=-1*(nums[i]+nums[j]);
                sort(curr.begin(),curr.end());
                smap.insert(curr);
            }

            umap[nums[j]]++;
        }

        umap[nums[i]]++;
    }

    for (auto &itr : smap) {
        sol.push_back(itr);
    }

    return sol;
}