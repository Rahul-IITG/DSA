#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();

    vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
    vector<vector<int>> vis(m,vector<int>(n,-1));

    queue<vector<int>> q;

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (mat[i][j]!=0) {
                continue;
            }

            vector<int> curr;
            curr.push_back(i);
            curr.push_back(j);
            q.push(curr);
            dist[i][j]=0;
            vis[i][j]=1;
        }
    }

    int s=q.size();
    vector<int> next;

    while (s) {
        vector<int> curr=q.front();
        q.pop();
        s--;

        if (curr[0]-1>=0&&vis[curr[0]-1][curr[1]]==-1) {
            vis[curr[0]-1][curr[1]]=1;
            dist[curr[0]-1][curr[1]]=dist[curr[0]][curr[1]]+1;
            next=curr;
            next[0]=next[0]-1;
            q.push(next);
            s++;
        }

        if (curr[0]+1<m&&vis[curr[0]+1][curr[1]]==-1) {
            vis[curr[0]+1][curr[1]]=1;
            dist[curr[0]+1][curr[1]]=dist[curr[0]][curr[1]]+1;
            next=curr;
            next[0]=next[0]+1;
            q.push(next);
            s++;
        }

        if (curr[1]-1>=0&&vis[curr[0]][curr[1]-1]==-1) {
            vis[curr[0]][curr[1]-1]=1;
            dist[curr[0]][curr[1]-1]=dist[curr[0]][curr[1]]+1;
            next=curr;
            next[1]=next[1]-1;
            q.push(next);
            s++;
        }

        if (curr[1]+1<n&&vis[curr[0]][curr[1]+1]==-1) {
            vis[curr[0]][curr[1]+1]=1;
            dist[curr[0]][curr[1]+1]=dist[curr[0]][curr[1]]+1;
            next=curr;
            next[1]=next[1]+1;
            q.push(next);
            s++;
        }
    }

    return dist;
}