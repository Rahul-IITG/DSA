#include <vector>

using namespace std;

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
    int m=arrayOne.size();
    int n=arrayTwo.size();

    if (m!=n) {
        return false;
    }
    if (m==0&&n==0) {
        return true;
    }
    if (m==0||n==0) {
        return false;
    }
    if (arrayOne[0]!=arrayTwo[0]) {
        return false;
    }

    vector<int> oneLeft;
    vector<int> oneRight;

    for (int i=1;i<m;i++) {
        if (arrayOne[i]<arrayOne[0]) {
            oneLeft.push_back(arrayOne[i]);
        }
        if (arrayOne[i]>=arrayOne[0]) {
            oneRight.push_back(arrayOne[i]);
        }
    }

    vector<int> twoLeft;
    vector<int> twoRight;

    for (int i=1;i<m;i++) {
        if (arrayTwo[i]<arrayTwo[0]) {
            twoLeft.push_back(arrayOne[i]);
        }
        if (arrayTwo[i]>=arrayTwo[0]) {
            twoRight.push_back(arrayOne[i]);
        }
    }

    m=oneLeft.size();
    n=twoLeft.size();

    if (m!=n) {
        return false;
    }

    m=oneRight.size();
    n=twoRight.size();

    if (m!=n) {
        return false;
    }

    return sameBsts(oneLeft, twoLeft) && sameBsts(oneRight, twoRight);
}
