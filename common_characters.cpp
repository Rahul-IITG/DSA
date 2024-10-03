#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> commonCharacters(vector<string> strings) {
    unordered_map<char, int> umap;
    int s=strings.size();
    int cs=strings[0].length();

    for (int i=0;i<cs;i++) {
        umap[strings[0][i]]++;
    }

    for (int i=1;i<s;i++) {
        cs=strings[i].length();
        unordered_map<char,int> cu;

        for (int j=0;j<cs;j++) {
            if (umap[strings[i][j]]>0) {
                cu[strings[i][j]]++;
            }
        }

        umap=cu;
    }

    vector<string> sol;

    for (auto &itr : umap) {
        string str="";
        str.push_back(itr.first);
        sol.push_back(str);
    }

    return sol;
}
