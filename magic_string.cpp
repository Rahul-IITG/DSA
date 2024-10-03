
#include <string>
#include <unordered_map>

using namespace std;

int magicString(string str) {
    int s=str.size();
    unordered_map<char,int> umap;

    for (int i=0;i<s;i++) {
        umap[str[i]]++;
    }

    int ans=INT_MAX;

    for (auto &itr: umap) {
        if (s-itr.second<ans) {
            ans=s-itr.second;
        }
    }

    return ans;
}
