#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int s=height.size();
    int left=0;
    int right=s-1;
    int sol=0;

    while (left<right) {
        sol=max(sol,min(height[left],height[right])*(right-left));

        if (height[left]<height[right]) {
            left++;
        }
        else {
            right--;
        }
    }

    return sol;
}