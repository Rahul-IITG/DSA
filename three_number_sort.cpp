#include <vector>
using namespace std;

vector<int> threeNumberSort(vector<int> array, vector<int> order) {
    int s=array.size();
    int index=0;

    for (int i=0;i<2;i++) {
        int val=order[i];

        for (int j=0;j<s;j++) {
            if (array[j]==val) {
                int temp=array[index];
                array[index]=array[j];
                array[j]=temp;
                index++;
            }
        }
    }

    return array;
}
