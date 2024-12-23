#include <vector>
using namespace std;

vector<int> sortMerge(vector<int> arr, int l, int r) {
    if (l==r) {
        return arr;
    }

    int middle=(l+r)/2;

    vector<int> left(arr.begin(),arr.begin()+middle+1);
    vector<int> right(arr.begin()+middle+1,arr.end());
    left=sortMerge(left,l,middle);
    right=sortMerge(right,middle+1,r);

    int li=left.size();
    int ri=right.size();
    int i=0;
    int j=0;
    vector<int> sol;

    while (i<li&&j<ri) {
        if (left[i]<=right[j]) {
            sol.push_back(left[i]);
            i++;
            continue;
        }

        sol.push_back(right[j]);
        j++;
    }

    while (i<li) {
        sol.push_back(left[i]);
        i++;
    }
    while (j<ri) {
        sol.push_back(right[j]);
        j++;
    }

    return sol;
}

void mergeSort(vector<int>& arr, int l, int r) {
    arr=sortMerge(arr,l,r);
    return;
}