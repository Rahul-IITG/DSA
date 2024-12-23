#include <vector>
using namespace std;

void explore(int index, vector<vector<int>> &edges, int &n, vector<int> &vis) {
    int s=edges[index].size();

    for (int i=0;i<s;i++) {
        if (vis[edges[index][i]]==0) {
            vis[edges[index][i]]=1;
            explore(edges[index][i],edges,n,vis);
        }
    }

    return;
}

int countComponents(int n, vector<vector<int>>& edge) {
    int s=edge.size();
    vector<vector<int>> edges(n);
    vector<int> vis(n,0);

    for (int i=0;i<s;i++) {
        edges[edge[i][0]].push_back(edge[i][1]);
        edges[edge[i][1]].push_back(edge[i][0]);
    }

    int sol=0;

    for (int i=0;i<n;i++) {
        if (vis[i]==0) {
            vis[i]=1;
            explore(i,edges,n,vis);
            sol++;
        }
    }

    return sol;
}