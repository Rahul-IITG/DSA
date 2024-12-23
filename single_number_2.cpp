#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int s=nums.size();
    int result=0;

    for (int i=0;i<s;i++) {
        result^=nums[i];
    }

    return result;
}