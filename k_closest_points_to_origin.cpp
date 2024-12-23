#include <vector>
using namespace std;

static bool comp_func(vector<int> &a, vector<int> &b) {
    return a[1]<b[1];
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    int s=points.size();
    vector<vector<int>> dist;

    for (int i=0;i<s;i++) {
        dist.push_back({i,points[i][0]*points[i][0]+points[i][1]*points[i][1]});
    }

    sort(dist.begin(),dist.end(),comp_func);
    vector<vector<int>> sol;

    for (int i=0;i<k;i++) {
        sol.push_back(points[dist[i][0]]);
    }

    return sol;
}