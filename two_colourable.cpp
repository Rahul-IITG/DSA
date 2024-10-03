#include <vector>
using namespace std;

bool explore(int index, vector<vector<int>> edges, vector<int> &vis, vector<int> &colour) {
    int s=edges[index].size();

    for (int i=0;i<s;i++) {
        if (vis[edges[index][i]]==1&&colour[edges[index][i]]==colour[index]) {
            return false;
        }
        if (vis[edges[index][i]]==0) {
            vis[edges[index][i]]=1;

            if (colour[index]==1) {
                colour[edges[index][i]]=0;
            }
            else {
                colour[edges[index][i]]=1;
            }

            if (!explore(edges[index][i],edges,vis,colour)) {
                return false;
            }
        }
    }

    return true;
}

bool twoColorable(vector<vector<int>> edges) {
    int s=edges.size();
    vector<int> vis(s,0);
    vector<int> colour(s,-1);

    for (int i=0;i<s;i++) {
        if (vis[i]==0) {
            vis[i]=1;
            colour[i]=0;

            if (!explore(i,edges,vis,colour)) {
                return false;
            }
        }
    }

    return true;
}
