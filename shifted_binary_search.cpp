#include <vector>
using namespace std;

int binarySearch(int left, int right, vector<int> array, int target) {
    while (left<=right) {
        int middle=(left+right)/2;

        if (array[middle]==target) {
            return middle;
        }
        if (target<array[middle]) {
            right=middle-1;
            continue;
        }
        if (array[middle]<target) {
            left=middle+1;
        }
    }

    return -1;
}

/*int shiftedBinarySearch(vector<int> array, int target) {
    int s=array.size();
    int min=INT_MAX;
    int index;

    for (int i=0;i<s;i++) {
        if (array[i]<min) {
            min=array[i];
            index=i;
        }
    }

    if (array[index]<=target&&target<=array[s-1]) {
        return binarySearch(index,s-1,array,target);
    }
    else {
        return binarySearch(0,index-1,array,target);
    }

    return -1;
}*/

int shiftedBinarySearch(vector<int> array, int target) {
    int s=array.size();

    int left=0;
    int right=s-1;

    while (left<right) {
        int middle=(left/right)/2;

        if (array[middle]<=target&&target<=array[right]) {
            return binarySearch(middle,right,array,target);
        }
        if (array[left]<=target&&target<=array[middle]) {
            return binarySearch(left,middle,array,target);
        }

        if (array[middle]<=target&&array[right]<target) {
            if (array[left]<=array[middle]) {
                left=middle;
                continue;
            }

            right=middle;
            continue;
        }

        if (target<=array[middle]&&target<=array[left]) {
            if (array[left]<=array[middle]) {
                left=middle;
                continue;
            }

            right=middle;
            continue;
        }
    }

    return -1;
}