#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
    int s=words.size();
    unordered_map<string, vector<int>> umap;

    for (int i=0;i<s;i++) {
        sort(words[i].begin(),words[i].end());
        umap[words[i]].push_back(i);
    }

    vector<vector<string>> sol;

    for (auto &itr: umap) {
        vector<string> curr;
        int k=itr.second.size();

        for (int i=0;i<k;i++) {
            curr.push_back(words[itr.second[i]]);
        }

        sol.push_back(curr);
    }

    return sol;
}
