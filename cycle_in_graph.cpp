#include <vector>
using namespace std;

bool explore(int index, vector<vector<int>> edges, vector<int> &vis) {
    int s=edges[index].size();

    for (int i=0;i<s;i++) {
        if (vis[edges[index][i]]==1) {
            return true;
        }

        vis[edges[index][i]]=1;

        if (explore(edges[index][i],edges,vis)) {
            return true;
        }

        vis[edges[index][i]]=0;
    }

    return false;
}

bool cycleInGraph(vector<vector<int>> edges) {
    int s=edges.size();
    vector<int> vis(s,0);

    for (int i=0;i<s;i++) {
        vis[i]=1;

        if (explore(i,edges,vis)) {
            return true;
        }

        vis[i]=0;
    }

    return false;
}
