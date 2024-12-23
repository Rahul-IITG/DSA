#include <deque>
#include <vector>
using namespace std;

vector<int> resultsArray(vector<int>& nums, int k) {
    int s=nums.size();
    vector<int> sol;
    deque<int> dq;

    for (int i=0;i<s-k;i++) {
        if (!dq.empty()&&dq.front()<i-k+1) {
            dq.pop_front();
        }

        if (!dq.empty()&&nums[i-1]+1!=nums[i]) {
            dq.clear();
        }

        dq.push_back(i);

        if (i>=k-1) {
            if (dq.size()==k) {
                sol.push_back(dq.back());
            }
            else {
                sol.push_back(-1);
            }
        }
    }

    return sol;
}