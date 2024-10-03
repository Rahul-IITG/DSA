#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
    int s=array.size();
    unordered_map<int,int> umap;
    sort(array.begin(), array.end());

    for (int i=0;i<s;i++) {
        umap[array[i]]=i+1;
    }

    vector<vector<int>> sol;

    for (int i=0;i<s;i++) {
        for (int j=i+1;j<s;j++) {
            if (umap[targetSum-(array[i]+array[j])]!=0 && (umap[array[j]]<umap[targetSum-(array[i]+array[j])])) {
                vector<int> curr;
                curr.push_back(array[i]);
                curr.push_back(array[j]);
                curr.push_back(targetSum-(array[i]+array[j]));
                sol.push_back(curr);
            }
        }

        umap[array[i]]=0;
    }

    return sol;
}
