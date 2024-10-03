#include <vector>
using namespace std;

vector<int> largestRange(vector<int> array) {
    int s=array.size();
    sort(array.begin(), array.end());

    vector<int> sol;
    int start=array[0];
    int end=array[0];
    vector<int> curr;
    curr.push_back(start);
    curr.push_back(end);

    for (int i=1;i<s;i++) {
        if (array[i]==array[i-1]+1) {
            end=array[i];
            continue;
        }
        if (end-start+1>curr[1]-curr[0]+1) {
            curr[0]=start;
            curr[1]=end;
        }
        start=array[i];
        end=array[i];
    }

    sol.push_back(curr[0]);
    return sol;
}
