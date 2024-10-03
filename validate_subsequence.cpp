#include <vector>

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    int ss = sequence.size();
    int as = array.size();

    int i=0;
    int j=0;

    while (i<ss && j<as) {
        if (sequence[i] == array[j]) {
            i++;
            j++;
            continue;
        }
        j++;
    }

    if (i==ss) {
        return true;
    }

    return false;
}