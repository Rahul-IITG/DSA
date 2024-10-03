#include <vector>
using namespace std;

vector<int> mergeSort(vector<int> array, int start, int end, vector<int> &index) {
    if (start>=end) {
        return array;
    }

    int middle=(start+end)/2;
    vector<int> left(array.begin()+start, array.begin()+middle);
    vector<int> right(array.begin()+middle, array.end());
    left=mergeSort(left, start, middle-1, index);
    right=mergeSort(right,middle, end, index);

    int ls=left.size();
    int rs=right.size();
    int i=0;
    int j=0;
    vector<int> sol;

    while (i<ls&&j<rs) {
        if (left[i]<=right[j]) {
            sol.push_back(left[i]);
            i++;
            continue;
        }
        if (left[i]>right[j]) {
            sol.push_back(right[j]);
            j++;
            index.push_back(i);
            continue;
        }
    }

    while (i<ls) {
        sol.push_back(left[i]);
        i++;
    }
    while (j<rs) {
        sol.push_back(right[j]);
        index.push_back(j);
        j++;
    }

    return sol;
}

vector<int> subarraySort(vector<int> array) {
    int s=array.size();
    int cmin=array[0];
    int cmax=array[s-1];

    for (int i=1;i<s;i++) {
        if (array[i-1]>array[i]&&array[i]<cmin) {
            cmin=array[i];
        }
    }

    for (int i=s-1;i>0;i--) {
        if (array[i-1]>array[i]&&array[i-1]>cmax) {
            cmax=array[i-1];
        }
    }

    vector<int> sol;

    if (cmin==array[0]&&cmax==array[s-1]) {
        sol.push_back(-1);
        sol.push_back(-1);
        return sol;
    }

    int start;
    int end;

    for (int i=0;i<s;i++) {
        if (array[i]>cmin) {
            start=i;
            break;
        }
    }

    for (int i=s-1;i>=0;i--) {
        if (array[i]<cmax) {
            end=i;
            break;
        }
    }

    sol.push_back(start);
    sol.push_back(end);

    return sol;
}
