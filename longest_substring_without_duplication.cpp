#include <string>
#include <unordered_map>
using namespace std;

string longestSubstringWithoutDuplication(string str) {
    int s=str.size();
    unordered_map<char,int> umap;
    int left=0;
    int right=0;
    int sol=INT_MIN;
    string ans;

    while (right<s) {
        if (umap[str[right]]==0) {
            umap[str[right]]=right+1;
            right++;
            continue;
        }

        if (right-left>sol) {
            sol=right-left;
            ans=str.substr(left,sol);
        }
        left=umap[str[right]];
        right=umap[str[right]];
        umap.clear();
    }

    if (right-left>sol) {
        sol=right-left;
        ans=str.substr(left,sol);
    }
    return ans;
}
