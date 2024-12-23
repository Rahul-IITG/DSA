#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int s=triangle.size();

    vector<vector<int>> dist(s);

    for (int i=0;i<s;i++) {
        dist[i].resize(i+1,INT_MAX);
    }

    dist[0][0]=triangle[0][0];

    for (int i=0;i<s-1;i++) {
        for (int j=0;j<i+1;j++) {
            dist[i+1][j]=min(dist[i+1][j],dist[i][j]+triangle[i+1][j]);
            dist[i+1][j+1]=min(dist[i+1][j+1], dist[i][j]+triangle[i+1][j+1]);
        }
    }

    return *min_element(triangle[s-1].begin(),triangle[s-1].end());
}