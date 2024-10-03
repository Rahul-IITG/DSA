#include <vector>
using namespace std;

vector<int> missingNumbers(vector<int> nums) {
    int s=nums.size();
    vector<int> sol;
    int sum=0;

    for (int i=0;i<s;i++) {
        int index = abs(nums[i])-1;

        if (index>=s) {
            sum=sum+index+1;
            continue;
        }

        nums[index]=nums[index]*1;
    }

    for (int i=0;i<s;i++) {
        if (abs(nums[i])>=s) {
            continue;
        }
        if (nums[i]>0) {
            sol.push_back(i);
        }
    }

    if (sol.size()==0) {
        sol.push_back(s-1);
        sol.push_back(s);
    }
    if (sol.size()==1) {
        sol.push_back(2*s-1-sum);
    }

    return sol;
}