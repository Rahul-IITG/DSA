#include <stack>
#include <vector>
#include <map>
using namespace std;

int oddEvenJumps(vector<int>& arr) {
    int s=arr.size();
    vector<int> nextOdd(s,-1);
    vector<int> nextEven(s,-1);
    map<int,int> mp;

    for (int i=s-1;i>=0;i--) {
        auto nextHigher=mp.lower_bound(arr[i]);

        if (nextHigher!=mp.end()) {
            nextOdd[i]=nextHigher->second;
        }

        auto nextLower=mp.upper_bound(arr[i]);

        if (nextLower!=mp.begin()) {
            nextLower--;
            nextEven[i]=nextLower->second;
        }

        mp[arr[i]]=i;
    }

    vector<bool> odd(s,false);
    vector<bool> even(s,false);
    odd[s-1]=true;
    even[s-1]=true;
    int count=1;

    for (int i=s-1;i>=0;i--) {
        if (nextOdd[i]!=-1) {
            odd[i]=even[nextOdd[i]];

            if (odd[i]) {
                count++;
            }
        }
        if (nextEven[i]!=-1) {
            even[i]=odd[nextEven[i]];
        }
    }

    return count;
}