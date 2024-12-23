#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int s=gas.size();
    int tg=0;
    int tc=0;
    int curr=0;
    int start=0;

    for (int i=0;i<s;i++) {
        tg=tg+gas[i];
        tc=tc+cost[i];
        curr=gas[i]-cost[i];

        if (curr<0) {
            start=i+1;
            curr=0;
        }
    }

    return tg>=tc ? start : -1;
}