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

    vector<int> curr(3);
    set<vector<int>> st;

    for (int i=0;i<s;i++) {
        umap[nums[i]]--;

        for (int j=i+1;j<s;j++) {
            if (umap[-1*(nums[i]+nums[j])]!=0) {
                curr[0]=nums[i];
                curr[1]=nums[j];
                curr[2]=-1*(nums[i]+nums[j]);
                sort(curr.begin(),curr.end());
                st.insert(curr);
            }
        }
    }

    vector<vector<int>> sol;

    for (auto &curr : st) {
        sol.push_back(curr);
    }

    return sol;
}