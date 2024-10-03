#include <vector>
using namespace std;

bool comp_func(vector<int> &a, vector<int> &b) {
    return a[0]<b[0];
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    int s=points.size();

    if (k>=s) {
        return points;
    }

    vector<vector<int>> dist(s);
    int curr;

    for (int i=0;i<s;i++) {
        curr=(points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
        dist.push_back({curr,i});
    }

    sort(dist.begin(),dist.end(),comp_func);
    vector<vector<int>> sol;

    for (int i=0;i<k;i++) {
        sol.push_back(points[dist[i][1]]);
    }

    return sol;
}