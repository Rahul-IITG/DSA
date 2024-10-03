#include <vector>
using namespace std;

string longestPalindrome(string str) {
    int s=str.length();
    int left,right;
    int index=0;
    int sol=0;

    for (int i=0;i<s-1;i++) {
        left=i;
        right=i+1;

        while (left>=0&&right<s) {
            if (str[left]==str[right]) {
                if (right-left+1>sol) {
                    sol=right-left+1;
                    index=left;
                }

                left--;
                right++;
                continue;
            }

            break;
        }
    }

    for (int i=1;i<s-2;i++) {
        left=i-1;
        right=i+1;

        while (left>=0&&right<s) {
            if (str[left]==str[right]) {
                if (right-left+1>sol) {
                    sol=right-left+1;
                    index=left;
                }

                left--;
                right++;
                continue;
            }

            break;
        }
    }

    return str.substr(index,sol);
}