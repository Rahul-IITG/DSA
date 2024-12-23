#include <string>
#include <unordered_map>
using namespace std;

string minWindow(string str, string text) {
    int s=str.size();
    int t=text.size();

    if (t>s) {
        return "";
    }

    unordered_map<char,int> smap;

    for (int i=0;i<s;i++) {
        smap[str[i]]++;
    }

    unordered_map<char,int> umap;

    for (int i=0;i<t;i++) {
        umap[text[i]]++;

        if (umap[text[i]]>smap[text[i]]) {
            return "";
        }
    }

    int left=0;
    int right=0;
    int count=umap.size();
    int sol=INT_MAX;
    int start=0;
    unordered_map<char,int> cmap;
    cmap=umap;

    while (right<s) {
        if (umap[str[right]]==1) {
            count--;
        }

        umap[str[right]]--;

        while (count==0) {
            if (right-left+1<sol) {
                sol=right-left+1;
                start=left;
            }

            umap[str[left]]++;

            if (cmap[str[left]]>0&&umap[str[left]]>0) {
                count++;
            }

            left++;
        }

        right++;
    }

    return sol==INT_MAX ? "" : str.substr(start,sol);
}