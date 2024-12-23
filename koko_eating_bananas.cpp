#include <vector>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int s=piles.size();
    int left=1;
    int right=*max_element(piles.begin(),piles.end());

    while (left<right) {
        int middle=(left+right)/2;
        int curr=0;

        for (int i=0;i<s;i++) {
            curr+=(piles[i]/middle)+(piles[i]%middle!=0);
        }

        if (curr<=h) {
            right=middle;
        }
        else {
            left=middle+1;
        }
    }

    return right;
}