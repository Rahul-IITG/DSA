#include <string>
#include <unordered_map>
using namespace std;

bool oneEdit(string stringOne, string stringTwo) {
    int os=stringOne.length();
    int ts=stringTwo.length();

    if (abs(os-ts)>1) {
        return false;
    }

    int edit=0;

    if (os>ts) {
        string temp=stringOne;
        stringOne=stringTwo;
        stringTwo=temp;
        int tem=os;
        os=ts;
        ts=tem;
    }

    if (os==ts) {
        for (int i=0;i<os;i++) {
            if (stringOne[i]!=stringTwo[i]) {
                edit++;
            }
        }

        if (edit>1) {
            return false;
        }
    }
    else {
        int j=0;

        for (int i=0;i<os;i++) {
            if (stringOne[i]!=stringTwo[j]) {
                j++;
                i--;
                edit++;
                continue;
            }

            j++;
        }
    }

    if (edit>1) {
        return false;
    }

    return true;
}