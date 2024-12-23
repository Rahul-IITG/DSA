#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class comp_func {
public:
    bool operator() (pair<int,int> &a, pair<int,int> &b) {
        return a.second>b.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    int s=nums.size();
    unordered_map<int,int> umap;

    for (int i=0;i<s;i++) {
        umap[nums[i]]++;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, comp_func> pq;

    for (auto itr : umap) {
        pq.push({itr.first,itr.second});
    }

    vector<int> sol;

    for (int i=0;i<k;i++) {
        sol.push_back(pq.top().first);
        pq.pop();
    }

    return sol;
}