#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    int s=edges.size();

    vector<vector<int>> edge(n);
    vector<int> count(n,0);

    for (int i=0;i<s;i++) {
        edge[edges[i][0]].push_back(edges[i][1]);
        edge[edges[i][1]].push_back(edges[i][0]);
        count[edges[i][0]]++;
        count[edges[i][1]]++;
    }

    queue<int> q;

    for (int i=0;i<n;i++) {
        if (count[i]==1) {
            q.push(i);
        }
    }

    vector<int> sol;

    while (!q.empty()) {
        s=q.size();
        sol.clear();

        for (int i=0;i<s;i++) {
            int curr=q.front();
            q.pop();
            int k=edge[curr].size();
            sol.push_back(curr);

            for (int j=0;j<k;j++) {
                count[edge[curr][j]]--;

                if (count[edge[curr][j]]==1) {
                    q.push(edge[curr][j]);
                }
            }
        }
    }

    return sol;
}