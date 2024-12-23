#include <unordered_map>
#include <unordered_set>
using namespace std;

bool knows(int a, int b);

int findCelebrity(int n) {
    int celebrity=0;

    for (int i=1;i<n;i++) {
        if (!knows(i,celebrity)) {
            celebrity=i;
        }
    }

    for (int i=0;i<n;i++) {
        if (i==celebrity) {
            continue;
        }

        if (knows(celebrity,i)||!knows(i,celebrity)) {
            return -1;
        }
    }

    return celebrity;
}