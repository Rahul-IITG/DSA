#include <string>
#include <unordered_map>
using namespace std;

bool check(string str, string text) {
    int s=str.size();
    int t=text.size();

    int dp[t+1][s+1];

    for (int i=0;i<=t;i++) {
        dp[i][0]=0;
    }
    for (int i=0;i<=s;i++) {
        dp[0][i]=0;
    }

    for (int i=1;i<=t;i++) {
        for (int j=1;j<=s;j++) {
            if (text[i-1]==str[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max( dp[i][j-1], dp[i-1][j] );
            }
        }
    }

    int i=t;
    int j=s;
    string sol="";

    while (i>=0&&j>=0) {
        if (text[i-1]==str[j-1]) {
            sol.push_back(text[i-1]);
            i--;
            j--;
            continue;
        }
        if (dp[i][j-1]>dp[i-1][j]) {
            j--;
        }
        else {
            i--;
        }
    }

    reverse(sol.begin(),sol.end());
    return text==sol;
}

bool interweavingStrings(string one, string two, string three) {
    if (one=="") {
        return two==three;
    }
    if (two=="") {
        return one==three;
    }
    if (three=="") {
        return false;
    }

    if (one[0]==three[0] && two[0]==three[0]) {
        return interweavingStrings(one.substr(1), two, three.substr(1)) || interweavingStrings(one, two.substr(1), three.substr(1));
    }
    if (one[0]==three[0]) {
        return interweavingStrings(one.substr(1), two, three.substr(1));
    }
    if (two[0]==three[0]) {
        return interweavingStrings(one, two.substr(1), three.substr(1));
    }

    return false;
}
