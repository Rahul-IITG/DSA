#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int findTheLongestSubstring(string str) {
    int s=str.size();

    unordered_map<int,int> umap;
    umap[0]=-1;
    int mask=0;
    int ans=0;

    for (int i=0;i<s;i++) {
        if (str[i]=='a') {
            mask=mask^(1 << 0);
        }
        if (str[i]=='e') {
            mask=mask^(1 << 1);
        }
        if (str[i]=='i') {
            mask=mask^(1 << 2);
        }
        if (str[i]=='o') {
            mask=mask^(1 << 3);
        }
        if (str[i]=='u') {
            mask=mask^(1 << 4);
        }

        if (umap.find(mask) != umap.end()) {
            ans=max(ans, i - umap[mask]);
        }
        else {
            umap[mask]=i;
        }
    }

    return ans;
}