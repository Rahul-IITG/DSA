#include <vector>
using namespace std;

bool isMonotonic(vector<int> array) {
    int s=array.size();

    if (s==1) {
        return true;
    }

    bool flag;

    for (int i=0;i<s-1;i++) {
        if (array[i]==array[i+1]) {
            if (i+1==s) {
                return true;
            }
            continue;
        }

        if (array[i]>array[i+1]) {
            flag=false;
            break;
        }

        flag=true;
        break;
    }

    for (int i=0;i<s-1;i++) {
        if (flag && array[i]>array[i+1]) {
            return false;
        }
        if (!flag && array[i]<array[i+1]) {
            return false;
        }
    }

    return true;
}
