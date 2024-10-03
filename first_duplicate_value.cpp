#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> array) {
    int s=array.size();

    for (int i=0;i<s;i++) {
        int index=abs(array[i])-1;

        if (array[index]<0) {
            return abs(array[i]);
        }

        array[index] = array[index]*-1;
    }

    return -1;
}
