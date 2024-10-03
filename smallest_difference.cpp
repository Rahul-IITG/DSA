#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());

    int m=arrayOne.size();
    int n=arrayTwo.size();

    int i=0;
    int j=0;
    vector<int> sol;
    int first;
    int second;
    int curr=10000;

    while (i<m && j<n) {
        if (curr>abs(arrayOne[i]-arrayTwo[j])) {
            first=arrayOne[i];
            second=arrayTwo[j];
            curr=abs(arrayOne[i]-arrayTwo[j]);
        }
        if (arrayOne[i]*arrayTwo[j]>0) {
            if (arrayOne[i]<=arrayTwo[j]) {
                i++;
                continue;
            }
            j++;
            continue;
        }
        if (arrayOne[i]*arrayTwo[j]<=0) {
            if (arrayOne[i]<=0) {
                i++;
                continue;
            }
            j++;
            continue;
        }


    }

    sol.push_back(first);
    sol.push_back(second);
    return sol;
}