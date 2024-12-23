#include <vector>
using namespace std;

int findParent(int x, vector<int> &parent) {
    if (parent[x]!=x) {
        parent[x]=findParent(parent[x], parent);
    }

    return parent[x];
}

void join(int x, int y, vector<int> &parent, vector<int> &rank) {
    int xp=findParent(x,parent);
    int yp=findParent(y,parent);

    if (xp!=yp) {

        if (rank[xp]<rank[yp]) {
            parent[xp]=yp;
        }
        else if (rank[xp]>rank[yp]) {
            parent[yp]=xp;
        }
        else {
            parent[yp]=xp;
            rank[xp]++;
        }
    }

    return;
}

bool comp_func(vector<int> &a, vector<int> &b) {
    return a[0]<b[0];
}

int earliestAcq(vector<vector<int>>& logs, int n) {
    int s=logs.size();
    sort(logs.begin(),logs.end(),comp_func);
    int count=0;
    vector<int> parent(n);
    vector<int> rank(n);

    for (int i=0;i<n;i++) {
        parent[i]=i;
        rank[i]=0;
    }

    int index=0;

    for (int i=0;i<s;i++) {
        if (findParent(logs[i][1],parent)!=findParent(logs[i][2],parent)) {
            join(logs[i][1],logs[i][2],parent,rank);
            count++;
        }

        if (count==n-1) {
            index=i;
            break;
        }
    }

    return count==n-1 ? logs[index][0] : -1;
}