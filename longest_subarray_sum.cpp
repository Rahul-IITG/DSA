#include <vector>
using namespace std;

vector<int> longestSubarrayWithSum(vector<int> array, int targetSum) {
    int s=array.size();
    int left=0;
    int right=0;
    vector<int> sol(2,-1);
    int curr=0;
    int sum=0;

    while (left<s&&right<s) {
        if (sum+array[right]==targetSum) {
            if (right-left+1>curr) {
                curr=right-left+1;
                sol[0]=left;
                sol[1]=right;
            }
            sum=sum+array[right];
            right++;
            continue;
        }
        if (sum+array[right]<targetSum) {
            sum=sum+array[right];
            right++;
            continue;
        }
        if (sum+array[right]>targetSum) {
            sum=sum-array[left];
            left++;
        }
    }

    if (sol[0]==-1) {
        return {};
    }

    return sol;
}
