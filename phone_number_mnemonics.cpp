#include <vector>
using namespace std;

void permutate(vector<vector<string>> pad, int index, int s, string number, vector<string> &sol, string curr, int k) {
    if (k==s) {
        sol.push_back(curr);
        return;
    }

    for (int i=index;i<s;i++) {
        if (number[i]=='0' || number[i]=='1') {
            string cc=curr;
            cc.push_back(number[i]);
            permutate(pad,i+1,s,number,sol,cc,k+1);
            continue;
        }

        int cn=int(number[i]-'0');
        int ps=pad[cn].size();

        for (int j=0;j<ps;j++) {
            string cc=curr;
            cc.append(pad[cn][j]);
            permutate(pad,i+1,s,number,sol,cc,k+1);
        }
    }

    return;
}

vector<string> phoneNumberMnemonics(string phoneNumber) {
    vector<vector<string>> pad(10);
    pad[2]={"a","b","c"};
    pad[3]={"d","e","f"};
    pad[4]={"g","h","i"};
    pad[5]={"j","k","l"};
    pad[6]={"m","n","o"};
    pad[7]={"p","q","r","s"};
    pad[8]={"t","u","v"};
    pad[9]={"x","y","z"};

    int s=phoneNumber.size();
    vector<string> sol;
    string curr="";
    permutate(pad,0,s,phoneNumber,sol,curr,0);
    return sol;
}
