#include <vector>
using namespace std;

int calculate(int a, int b, int x) {
    return (a*x*x)+(b*x);
}

vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    int s=nums.size();
    int left=0;
    int right=s-1;
    vector<int> sol;

    while (left<right) {
        if (a<0) {
            int leftValue=calculate(a,b,nums[left]);
            int rightValue=calculate(a,b,nums[right]);

            if (leftValue<=rightValue) {
                sol.push_back(leftValue);
                left++;
            }
            else {
                sol.push_back(rightValue);
                right--;
            }
        }
        else {
            int leftValue=calculate(a,b,nums[left]);
            int rightValue=calculate(a,b,nums[right]);

            if (leftValue>=rightValue) {
                sol.push_back(leftValue);
                left++;
            }
            else {
                sol.push_back(rightValue);
                right--;
            }
        }
    }

    if (a>0) {
        reverse(sol.begin(),sol.end());
    }

    return sol;
}