#include <vector>
using namespace std;

int bestSeat(vector<int> seats) {
    int s=seats.size();
    vector<int> lst(0,s);
    int count=0;
    int index;

    for (int i=1;i<s;i++) {
        if (seats[i]==0) {
            lst[i]=lst[i-1]+1;

            if (count<lst[i]) {
                count=lst[i];
                index=i;
            }
        }
    }

    if (count=0) {
        return -1;
    }

    return index-(count/2);
}
