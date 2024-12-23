#include <string>
#include <unordered_map>
using namespace std;

int maximumLengthSubstring(string str) {
    int s=str.size();
    unordered_map<char,int> umap;

    for (int i=0;i<s;i++) {
        umap[str[i]]++;
    }

    int count=umap.size();

    int left=0;
    int right=0;
    unordered_map<char,int> curr;
    int length=0;

    while (right<s) {
        curr[str[right]]++;

        while (curr[str[right]]>2) {
            curr[str[left]]--;
            left++;
        }

        right++;
        length=max(length,right-left);
    }

    return length;
}
