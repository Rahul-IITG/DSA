#include <string>
using namespace std;

string caesarCypherEncryptor(string str, int key) {
    int s=str.length();
    int val;
    string ans="";

    for (int i=0;i<s;i++) {
        val=int(str[i])+key;

        if (val>122) {
            val=97+(val-122-1);
        }

        char c = char(val);
        ans.push_back(c);
    }

    return ans;
}