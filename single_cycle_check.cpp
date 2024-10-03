#include <vector>
using namespace std;

bool traverse(vector<int> array, vector<int> &vis, int index, int s, int steps, int start, int count) {
    int k;

    if (steps>0) {
        k=(index+steps)%s;
        if (k==start&&count==s) {
            return true;
        }
        if (k==start) {
            return false;
        }
        if (vis[k]==1) {
            return false;
        }
        if (traverse(array,vis,k,s,array[k],start,count+1)) {
            vis[k]=1;
            return true;
        }
        vis[k]=-1;
    }
    if (steps<0) {
        if (index+steps<0) {
            k=(index+steps)%s;
            k=s+k;
        }
        else {
            k=(index+steps)%s;
        }

        if (k==start&&count==s) {
            return true;
        }
        if (k==start) {
            return false;
        }
        if (vis[k]==1) {
            return false;
        }
        if (traverse(array,vis,k,s,array[k],start,count+1)) {
            vis[k]=1;
            return true;
        }
        vis[k]=-1;
    }

    return false;
}

bool hasSingleCycle(vector<int> array) {
    int s=array.size();
    vector<int> vis(s,-1);

    for (int i=0;i<s;i++) {
        if (array[i]==0) {
            continue;
        }
        vis[i]=1;
        int count=1;
        if (traverse(array,vis,i,s,array[i],i,count)) {
            return true;
        }
        vis[i]=-1;
    }

    return false;
}