#include <unordered_map>
#include <vector>
using namespace std;

void permutate(int size, int &s, vector<int> &array, vector<int> curr, vector<vector<int>> &sol, unordered_map<int,int> &umap, unordered_map<int,int> cmap) {
    if (size==s) {
        sol.push_back(curr);
        return;
    }

    for (int i=0;i<s;i++) {
        if (cmap[array[i]]<umap[array[i]]) {
            cmap[array[i]]++;
            curr.push_back(array[i]);
            permutate(size+1,s,array,curr,sol,umap,cmap);
            cmap[array[i]]--;
            curr.pop_back();
        }
    }

    return;
}

vector<vector<int>> getPermutations(vector<int> array) {
    int s=array.size();

    vector<int> curr;
    vector<vector<int>> sol;
    unordered_map<int,int> umap;

    for (int i=0;i<s;i++) {
        umap[array[i]]++;
    }

    unordered_map<int,int> cmap;
    permutate(0,s,array,curr,sol,umap,cmap);

    return sol;
}
