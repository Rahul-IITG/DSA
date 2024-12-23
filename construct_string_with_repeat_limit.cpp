#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

string repeatLimitedString(string str, int repeatLimit) {
    int s=str.size();
    unordered_map<char,int> umap;

    for (int i=0;i<s;i++) {
        umap[str[i]]++;
    }

    string sol="";
    priority_queue<char> pq;

    for (auto itr : umap) {
        pq.push(itr.first);
    }

    while (!pq.empty()) {
        char curr=pq.top();
        pq.pop();

        int use=min(umap[curr],repeatLimit);
        sol.append(use,curr);

        umap[curr]-=use;

        if (umap[curr]>0&&!pq.empty()) {
            char next=pq.top();
            pq.pop();
            sol.append(1,next);
            umap[next]--;

            if (umap[next]>0) {
                pq.push(next);
            }

            pq.push(curr);
        }
    }

    return sol;
}