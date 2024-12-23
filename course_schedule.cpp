#include <vector>
using namespace std;

bool explore(int index, int numCourses, vector<vector<int>> &edges, vector<int> &vis, vector<int> &st) {
    int s=edges[index].size();

    for (int i=0;i<s;i++) {
        if (st[edges[index][i]]==1) {
            return true;
        }

        if (vis[edges[index][i]]==0) {
            vis[edges[index][i]]=1;
            st[edges[index][i]]=1;

            if (explore(edges[index][i],numCourses,edges,vis,st)) {
                return true;
            }

            st[edges[index][i]]=0;
        }
    }

    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> edges(numCourses);
    int s=prerequisites.size();

    for (int i=0;i<s;i++) {
        edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    vector<int> vis(numCourses,0);
    vector<int> st(numCourses,0);

    for (int i=0;i<numCourses;i++) {
        if (vis[i]==0) {
            vis[i]=1;
            st[i]=1;

            if (explore(i,numCourses,edges,vis,st)) {
                return false;
            }

            st[i]=0;
        }
    }

    return true;
}