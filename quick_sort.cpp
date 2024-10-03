#include <vector>
using namespace std;

vector<int> quickSort(vector<int> array) {
    int s=array.size();

    if (s==0||s==1) {
        return array;
    }

    int pivot=array[s-1];
    vector<int> first;
    vector<int> second;

    for (int i=0;i<s-1;i++) {
        if (array[i]<=pivot) {
            first.push_back(array[i]);
        }
        else {
            second.push_back(array[i]);
        }
    }

    first=quickSort(first);
    second=quickSort(second);
    vector<int> sol;
    int fs=first.size();
    int ss=second.size();

    for (int i=0;i<fs;i++) {
        sol.push_back(first[i]);
    }
    sol.push_back(pivot);
    for (int i=0;i<ss;i++) {
        sol.push_back(second[i]);
    }

    return sol;
}
