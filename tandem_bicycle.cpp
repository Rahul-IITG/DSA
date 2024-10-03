#include <vector>
using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds, bool fastest) {
    sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
    sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
    int s = redShirtSpeeds.size();

    if (fastest) {
        reverse(redShirtSpeeds.begin(), redShirtSpeeds.end());
    }

    int ans=0;

    for (int i=0;i<s;i++) {
        ans = ans + max(redShirtSpeeds[i], blueShirtSpeeds[i]);
    }

    return ans;
}