#include <string>
#include <unordered_map>
using namespace std;

bool isValid(int left, int right, int k, int maxF) {
    return right-left+1-maxF<=k;
}

int characterReplacement(string str, int k) {
    int s=str.size();

    unordered_map<char,int> umap;
    int left=0;
    int right=0;
    int count=0;
    int sol=0;

    while (right<s) {
        umap[str[right]]++;

        int maxF=0;

        for (auto itr : umap) {
            maxF=max(maxF,itr.second);
        }

        while (!isValid(left,right,k,maxF)) {
            umap[str[left]]--;
            left++;
        }

        sol=max(sol,right-left+1);
        right++;
    }

    return sol;
}