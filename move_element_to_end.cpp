#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
    int s=array.size();
    int index=-1;
    int i=0;

    while (i<s) {
        if (array[i]==toMove) {
            index=i;
            i++;
            continue;
        }
        if (index!=-1&&array[i]!=toMove) {
            int temp=array[i];
            array[i]=toMove;
            array[index]=temp;
            index++;
            i++;
        }
    }

    return array;
}
