#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
    int s = array.size();
    unordered_map<int,int> ump;

    for (int i=0;i<s;i++) {
        ump[array[i]]++;
    }

    vector<int> sol;

    for (int i=0;i<s;i++) {
        if (targetSum - array[i] != array[i] && ump[targetSum - array[i]] != 0) {
            sol.push_back(targetSum - array[i]);
            sol.push_back(array[i]);
            break;
        }
    }

    return sol;
}