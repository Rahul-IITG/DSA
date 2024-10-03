#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
    int i=0;
    int j=array.size()-1;
    int middle;

    while (i<j) {
        middle=(i+j)/2;

        if (array[middle]==target) {
            return middle;
        }
        if (array[middle]<target) {
            i=middle+1;
            continue;
        }

        j=middle;
    }

    if (array[middle]==target) {
        return middle;
    }

    return -1;
}