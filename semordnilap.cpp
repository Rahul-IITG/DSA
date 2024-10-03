#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> semordnilap(vector<string> words) {
    int s=words.size();
    vector<string> cp=words;
    unordered_map<string,int> umap;

    for (int i=0;i<s;i++) {
        umap[words[i]]++;
        reverse(words[i].begin(), words[i].end());
    }

    vector<vector<string>> sol;
    for (int i=0;i<s;i++) {
        if (umap[words[i]]>0 && umap[cp[i]]>0) {
            vector<string> curr;
            curr.push_back(words[i]);
            curr.push_back(cp[i]);
            sol.push_back(curr);

            umap[words[i]]=0;
            umap[cp[i]]=0;
        }
    }

    return sol;
}