#include <vector>

#include "../../../../Library/Developer/CommandLineTools/SDKs/MacOSX14.4.sdk/usr/include/setjmp.h"
using namespace std;

vector<int> selectionSort(vector<int> array) {
    int s=array.size();

    for (int i=0;i<s;i++) {
        int min=array[i];
        int index=i;

        for (int j=i;j<s;j++) {
            if (array[j]<min) {
                min=array[j];
                index=j;
            }
        }

        if (index!=i) {
            int temp=array[i];
            array[i]=array[index];
            array[index]=temp;
        }
    }

    return array;
}