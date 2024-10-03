#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
    int s=array.size();
    int ans=array[0];

    for (int i=1;i<s;i++) {
        if (array[i]+array[i-1]>array[i]) {
            array[i]=array[i]+array[i-1];
        }
        if (array[i]>ans) {
            ans=array[i];
        }
    }

    return ans;
}