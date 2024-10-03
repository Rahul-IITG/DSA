#include <string>
#include <unordered_map>
using namespace std;

int firstNonRepeatingCharacter(string str) {
    int s= str.length();
    unordered_map<char,int> umap;
    unordered_map<char,int> index;

    for (int i=0;i<s;i++) {
        if (umap[str[i]]!=0) {
            index[str[i]]=-1;
            continue;
        }

        umap[str[i]]++;
        index[str[i]]=i;
    }

    int ans=10000;

    for (auto &itr: index) {
        if (itr.second<ans&&itr.second!=-1) {
            ans=itr.second;
        }
    }

    return ans;
}