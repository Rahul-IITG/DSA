#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int s=wordList.size();

    unordered_set<string> set(wordList.begin(),wordList.end());

    if (set.find(endWord)==set.end()) {
        return 0;
    }

    unordered_map<string,int> umap;

    for (int i=0;i<s;i++) {
        umap[wordList[i]]++;
    }

    queue<pair<string,int>> q;
    q.push({beginWord,1});

    while (!q.empty()) {
        pair<string,int> p=q.front();
        string curr=p.first;
        int steps=p.second;
        q.pop();
        int f=curr.size();

        for (int i=0;i<f;i++) {
            char original=curr[i];

            for (char c='a';c<='z';c++) {
                if (c==original) {
                    continue;
                }

                curr[i]=c;

                if (curr==endWord) {
                    return steps+1;
                }

                if (umap[curr]!=0) {
                    q.push({curr,steps+1});
                    umap[curr]=0;
                }
            }

            curr[i]=original;
        }
    }

    return 0;
}