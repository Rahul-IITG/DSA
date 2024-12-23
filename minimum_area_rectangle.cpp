#include <unordered_set>
#include <vector>
using namespace std;

int minAreaRect(vector<vector<int>>& points) {
    int s=points.size();
    unordered_set<pair<int,int>> st;

    for (int i=0;i<s;i++) {
        st.insert({points[i][0],points[i][1]});
    }

    int sol=0;

    for (int i=0;i<s;i++) {
        for (int j=i+1;j<s;j++) {
            if (points[i][0]!=points[j][0]&&points[i][1]!=points[j][1]) {
                if (st.count({points[i][0],points[j][1]})&&st.count({points[j][0],points[i][1]})) {
                    sol=min(sol,abs(points[i][0]-points[j][0])*abs(points[i][1]-points[j][1]));
                }
            }
        }
    }

    return sol;
}