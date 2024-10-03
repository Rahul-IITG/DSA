#include <vector>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
    int s=array.size();
    vector<int> sol;

    for (int i=0;i<3;i++) {
        int max = -10000;
        int min = 10000;
        int index;

        for (int j=0;j<s;j++) {
            if (array[i]>max) {
                max=array[i];
                index=i;
                continue;
            }
            if (array[i]<min) {
                min=array[i];
            }
        }

        sol.push_back(max);
        array[index]=min;
    }

    return sol;
}