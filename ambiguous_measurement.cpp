#include <vector>
using namespace std;

bool recur(vector<vector<int>> measuringCups, int currl, int currh, int low, int high) {
    if (low<=currl&&currh<=high) {
        return true;
    }

    int s=measuringCups.size();

    for (int i=0;i<s;i++) {
        if (recur(measuringCups,currl+measuringCups[i][0],currh+measuringCups[i][1],low,high)) {
            return true;
        }
    }

    return false;
}

bool ambiguousMeasurements(vector<vector<int>> measuringCups, int low, int high) {
    int s=measuringCups.size();
    int currl=0;
    int currh=0;

    for (int i=0;i<s;i++) {
        if (recur(measuringCups,currl+measuringCups[i][0],currh+measuringCups[i][1],low,high)) {
            return true;
        }
    }

    return false;
}