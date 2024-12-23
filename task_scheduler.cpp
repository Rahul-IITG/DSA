#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    int s=tasks.size();
    unordered_map<int,int> umap;

    for (int i=0;i<s;i++) {
        umap[tasks[i]]++;
    }

    priority_queue<int> heap;

    for (auto itr : umap) {
        heap.push(itr.second);
    }

    int sol=0;

    while (!heap.empty()) {
        vector<int> temp;
        int cycle=n+1;

        for (int i=0;i<cycle;i++) {
            if (!heap.empty()) {
                temp.push_back(heap.top());
                heap.pop();
            }
        }

        s=temp.size();

        for (int i=0;i<s;i++) {
            int freq=temp[i];
            freq--;

            if (freq>0) {
                heap.push(freq);
            }
        }

        sol += heap.empty() ? s : cycle;
    }

    return sol;
}