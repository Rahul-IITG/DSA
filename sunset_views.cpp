#include <string>
#include <vector>
using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction) {
    int s=buildings.size();
    vector<int> sol;

    if (direction=="EAST") {
        reverse(buildings.begin(),buildings.end());
    }

    int curr=INT_MIN;

    for (int i=0;i<s;i++) {
        if (buildings[i]>curr) {
            curr=buildings[i];
            if (direction=="EAST") {
                sol.push_back(s-1-i);
            }
            else {
                sol.push_back(i);
            }
        }
    }

    return sol;
}
