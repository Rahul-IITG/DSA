#include <unordered_map>
#include <vector>
using namespace std;

int longestSubsequence(vector<int>& arr, int difference) {
    int s=arr.size();

    unordered_map<int,int> umap;

    for (int i=0;i<s;i++) {
        if (umap[arr[i]-difference]!=0) {
            umap[arr[i]]=umap[arr[i]-difference]+1;
            continue;
        }

        umap[arr[i]]=1;
    }

    int sol=0;

    for (auto itr : umap) {
        sol=max(sol,itr.second);
    }

    return sol;
}