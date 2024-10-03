#include <unordered_map>
#include <vector>
using namespace std;

vector<char> minimumCharactersForWords(vector<string> words) {
    int s=words.size();
    unordered_map<char,int> umap;

    for (int i=0;i<s;i++) {
        unordered_map<char,int> curr;
        int k=words[i].size();

        for (int j=0;j<k;j++) {
            curr[words[i][j]]++;

            if (curr[words[i][j]]>umap[words[i][j]]) {
                umap[words[i][j]]=curr[words[i][j]];
            }
        }
    }

    vector<char> sol;

    for (auto &itr: umap) {
        int k=itr.second;

        for (int i=0;i<k;i++) {
            sol.push_back(itr.first);
        }
    }

    return sol;
}