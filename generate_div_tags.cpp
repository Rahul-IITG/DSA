#include <vector>
using namespace std;

void recur(int first, int second, int n, vector<string> sol, string curr) {
    if (second==n) {
        sol.push_back(curr);
        return;
    }

    if (first<n) {
        recur(first+1,second,n,sol,curr+"(");
    }
    if (second<n&&second<first) {
        recur(first,second+1,n,sol,curr+")");
    }

    return;
}

vector<string> generateDivTags(int n) {
    int first=0;
    int second=0;
    vector<string> sol;
    string curr="";
    recur(first,second,n,sol,curr);

    return sol;
}