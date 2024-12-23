#include <stack>
#include <unordered_map>
using namespace std;

class FreqStack {
public:
    unordered_map<int,int> umap;
    unordered_map<int,stack<int>> st;
    int maxF=INT_MIN;

    FreqStack() {
        
    }
    
    void push(int val) {
        umap[val]++;
        int freq=umap[val];

        if (freq>maxF) {
            maxF=freq;
        }

        st[freq].push(val);
    }
    
    int pop() {
        int ans=st[maxF].top();
        st[maxF].pop();

        umap[ans]--;

        if (st[maxF].empty()) {
            maxF--;
        }

        return ans;
    }
};