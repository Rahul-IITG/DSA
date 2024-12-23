#include <deque>
#include <vector>
using namespace std;

long long continuousSubarrays(vector<int>& nums) {
    int s=nums.size();
    deque<int> minQ;
    deque<int> maxQ;

    long long sol=0;
    int left=0;
    int right=0;

    while (right<s) {
        while (!minQ.empty()&&nums[minQ.back()]>nums[right]) {
            minQ.pop_back();
        }

        minQ.push_back(right);

        while (!maxQ.empty()&&nums[maxQ.back()]<nums[right]) {
            maxQ.pop_back();
        }

        maxQ.push_back(right);

        while (!minQ.empty()&&!maxQ.empty()&&nums[maxQ.front()]-nums[minQ.front()]>2) {
            if (maxQ.front()<minQ.front()) {
                left=maxQ.front()+1;
                maxQ.pop_front();
            }
            else {
                left=minQ.front()+1;
                minQ.pop_front();
            }
        }

        sol=sol+(right-left+1);
        right++;
    }

    return sol;
}