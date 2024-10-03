#include <vector>
using namespace std;

void correctSol(int left, int right, vector<int> array, int &sol) {
    while (left<=right) {
        int middle=(left+right)/2;

        if (array[middle]<middle) {
            right=middle-1;
            continue;
        }
        if (array[middle]>middle) {
            left=middle+1;
            continue;
        }
        if (array[middle]==middle) {
            sol=middle;
            correctSol(left,middle-1,array,sol);
        }
    }
}

int indexEqualsValue(vector<int> array) {
    int s=array.size();

    int left=0;
    int right=s-1;
    int sol;

    while (left<=right) {
        int middle=(left+right)/2;

        if (array[middle]<middle) {
            right=middle-1;
            continue;
        }
        if (array[middle]>middle) {
            left=middle+1;
            continue;
        }
        if (array[middle]==middle) {
            sol=middle;
            correctSol(left,middle-1,array,sol);
        }
    }

    return -1;
}