#include <queue>
#include <string>
using namespace std;

class comp_func {
    public:
    bool operator(pair<char,int> &a, pair<char,int> &b) {
        return a.second > b.second;
    }
};

string reorganizeString(string str) {
    int s=str.size();

    priority_queue<pair<char,int>, vector<pair<char,int>>, comp_func> pq;
    unordered_map<char,int> umap;

    for (int i=0;i<s;i++) {
        umap[str[i]]++;
    }

    for (auto itr : umap) {
        pq.push({itr.first,itr.second});
    }

    string sol="";

    while (pq.size()>=2) {
        auto curr1=pq.top();
        pq.pop();
        auto curr2=pq.top();
        pq.pop();

        sol.push_back(curr1.first);
        sol.push_back(curr2.first);
        curr1.second--;
        curr2.second--;

        if (curr1.second>0) {
            pq.push({curr1.first,curr1.second});
        }
        if (curr2.second>0) {
            pq.push({curr2.first,curr2.second});
        }
    }

    if (pq.size()==1) {
        auto curr=pq.top();

        if (curr.second>1) {
            return "";
        }

        sol.push_back(curr.first);
    }

    return sol;
}