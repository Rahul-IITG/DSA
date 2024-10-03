#include <vector>
using namespace std;

int majorityElement(vector<int> array) {
    int s=array.size();
    int count=1;
    int curr=array[0];

    for (int i=1;i<s;i++) {
        if (array[i]!=curr) {
            count--;

            if (count==0) {
                curr=array[i];
                count=1;
            }

            continue;
        }

        count++;
    }

    return curr;
}
