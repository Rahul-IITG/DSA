#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findAnagrams(string str, string p) {
    int s=p.size();
    unordered_map<char,int> umap;

    for (int i=0;i<s;i++) {
        umap[p[i]]++;
    }

    int count=umap.size();
    unordered_map<char,int> cmap;
    cmap=umap;
    int left=0;
    int right=0;
    vector<int> sol;
    s=str.size();

    while (right<s) {
        if (cmap[str[right]]==0) {
            right++;
            left=right;
            umap=cmap;
            count=cmap.size();
            continue;
        }
        if (umap[str[right]]==0) {
            umap[str[left]]++;

            if (umap[str[left]]==1) {
                count++;
            }

            left++;
            continue;
        }

        if (umap[str[right]]==1) {
            count--;
        }

        umap[str[right]]--;

        if (count==0) {
            sol.push_back(left);
            left++;
            umap[str[left]]++;
            count++;
        }

        right++;
    }

    return sol;
}