#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
    int s=array.size();

    if (s==0) {
        return 0;
    }

    for (int i=0;i<s;i++) {
        if (i-2<0) {
            continue;
        }
        if (i-3<0) {
            array[i]=array[i]+array[i-2];
            continue;
        }
        array[i]=max(array[i]+array[i-2],array[i]+array[i-3]);
    }

    return *max_element(array.begin(),array.end());
}
