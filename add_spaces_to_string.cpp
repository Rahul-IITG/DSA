#include <string>
#include <vector>
using namespace std;

string addSpaces(string str, vector<int>& spaces) {
    int s=str.size();

    string sol="";
    string curr="";
    int index=0;

    for (int i=0;i<s;i++) {
        if (index<spaces.size()&&i!=spaces[index]) {
            curr.push_back(str[i]);
            continue;
        }

        if (index<spaces.size()) {
            sol.append(curr+" ");
            index++;
            curr="";
            i--;
        }
        else {
            curr.push_back(str[i]);
        }
    }

    if (curr!="") {
        sol.append(curr);
    }

    return sol;
}