#include <string>

bool isPalindrome(string str) {
    int s=str.length();
    int i=0;
    int j=s-1;

    while (i<=j) {
        if (str[i]!=str[j]) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}
