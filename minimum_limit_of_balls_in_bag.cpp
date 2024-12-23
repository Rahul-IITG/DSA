#include <vector>
using namespace std;

bool isValid(int &maxBalls, int &maxOperations, vector<int> &nums, int &s) {
    int operations=0;

    for (int i=0;i<s;i++) {
        operations+=ceil(nums[i]/maxBalls)-1;
    }

    if (operations<=maxOperations) {
        return true;
    }

    return false;
}

int minimumSize(vector<int>& nums, int maxOperations) {
    int s=nums.size();

    int left=1;
    int right=0;

    for (int i=0;i<s;i++) {
        right=max(right,nums[i]);
    }

    while (left<=right) {
        int middle=(left+right)/2;

        if (isValid(right,maxOperations,nums,s)) {
            right=middle;
        }
        else {
            left=middle+1;
        }
    }

    return left;
}