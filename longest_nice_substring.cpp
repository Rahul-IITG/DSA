#include <string>
#include <unordered_map>
using namespace std;

string longestNiceSubstring(string str) {
    int s=str.size();

    unordered_map<char,int> umap;

    for (int i=0;i<s;i++) {
        umap[str[i]]++;
    }

    int left=0;
    int right=0;

    while (right<s) {
        if (int(str[right])<=90) {
            if (umap[tolower(str[right])]==0) {

            }
        }
        else {
            if (umap[toupper(str[right])]==0) {

            }
        }
    }
}