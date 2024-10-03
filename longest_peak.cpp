#include <vector>
using namespace std;

int longestPeak(vector<int> array) {
    int s=array.size();
    bool flag=false;
    bool dec=false;

    if (s==0||s==1) {
        return 0;
    }

    int i=0;
    int j=1;
    int ans=0;

    while (j<s) {
        if (!flag) {
            if (array[j-1]>=array[j]) {
                j++;
                continue;
            }
            if (array[j-1]<array[j]) {
                i=j-1;
                flag=true;
                dec=false;
                continue;
            }
        }
        if (flag) {
            if (array[j-1]<array[j]&&dec==false) {
                j++;
                continue;
            }
            if (array[j-1]<array[j]&&dec==true) {
                i=j-1;
                j++;
                continue;
            }
            if (array[j-1]==array[j]) {
                i=j;
                flag=false;
                continue;
            }
            if (array[j-1]>array[j]) {
                if (ans<j-i+1) {
                    ans=j-i+1;
                }
                j++;
                dec=true;
            }
        }
    }

    return ans;
}
