#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
    int s=array.size();
    sort(array.begin(),array.end());
    vector<vector<int>> sol;

    for (int i=0;i<s-2;i++) {
        for (int j=i+1;j<s-1;j++) {
            int left=j+1;
            int right=s-1;

            while (left<right) {
                if (targetSum==array[i]+array[j]+array[left]+array[right]) {
                    vector<int> curr;
                    curr.push_back(array[i]);
                    curr.push_back(array[j]);
                    curr.push_back(array[left]);
                    curr.push_back(array[right]);
                    sol.push_back(curr);
                    break;
                }
                if (targetSum>array[i]+array[j]+array[left]+array[right]) {
                    left++;
                    continue;
                }
                if (targetSum<array[i]+array[j]+array[left]+array[right]) {
                    right--;
                }
            }
        }
    }

    return sol;
}