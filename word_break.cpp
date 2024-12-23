#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool wordBreak(string str, vector<string>& wordDict) {
    int s=wordDict.size();
    unordered_map<string,int> umap;

    for (int i=0;i<s;i++) {
        umap[wordDict[i]]=1;
    }

    s=str.size();

    vector<int> dp(s+1,false);
    dp[0]=true;

    for (int i=1;i<=s;i++) {
        for (int j=0;j<i;j++) {
            if (dp[j]&&umap[str.substr(j,i-j)]==1) {
                dp[i]=true;
                break;
            }
        }
    }

    return dp[s];
}