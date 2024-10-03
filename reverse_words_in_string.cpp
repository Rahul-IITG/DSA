#include <string>
#include <vector>
using namespace std;

string reverseWordsInString(string str) {
    int s=str.size();

    string curr="";
    string sol="";
    vector<string> lst;

    for (int i=0;i<s;i++) {
        if (str[i]==' ') {
            lst.push_back(curr);
            curr=" ";
            continue;
        }
        else {
            curr.push_back(str[i]);
        }
    }

    s=lst.size();

    for (int i=s-1;i>=0;i--) {
        sol=sol+lst[i];
    }

    return sol;
}
