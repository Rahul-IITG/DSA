#include <string>
using namespace std;

string runLengthEncoding(string str) {
    int s=str.length();
    int count = 1;
    string ans="";
    char curr=str[0];

    for (int i=1;i<s;i++) {
        if (curr==str[i]) {
            count++;
            if (count==9) {
                string cc=to_string(count);
                ans.append(cc);
                ans.push_back(curr);
                count=1;
            }
            continue;
        }

        string cc=to_string(count);
        ans.append(cc);
        ans.push_back(curr);
        curr=str[i];
        count=1;
    }

    return ans;
}
