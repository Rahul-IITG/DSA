#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

int racecar(int target) {
    unordered_set<string> uset;
    queue<vector<int>> q;
    q.push({0,1,0});
    uset.insert("0,1");

    while (!q.empty()) {
        auto curr=q.front();
        q.pop();

        if (curr[0]==target) {
            return curr[2];
        }

        int newPos=curr[0]+curr[1];
        int newSp=2*curr[1];
        string str=to_string(newPos)+","+to_string(newSp);

        if (abs(newPos)<=2*target&&uset.find(str)==uset.end()) {
            q.push({newPos,newSp,1+curr[2]});
            uset.insert(str);
        }

        newSp=curr[1]>0 ? -1 : 1;
        str=to_string(curr[0])+","+to_string(newSp);

        if (uset.find(str)==uset.end()) {
            q.push({curr[0],newSp,1+curr[2]});
            uset.insert(str);
        }
    }

    return -1;
}