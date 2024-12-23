#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int s=temperatures.size();
    vector<int> sol;
    stack<int> st;
    int i=s-1;

    while (i>=0) {
        if (st.empty()) {
            sol.push_back(0);
            st.push(i);
            i--;
            continue;
        }

        while (!st.empty()&&temperatures[st.top()]<=temperatures[i]) {
            st.pop();
        }

        if (st.empty()) {
            sol.push_back(0);
            st.push(i);
            i--;
            continue;
        }
        if (temperatures[st.top()]>temperatures[i]) {
            sol.push_back(i);
            st.push(i);
            i--;
        }
    }

    reverse(sol.begin(),sol.end());

    for (int i=0;i<s;i++) {
        if (sol[i]!=0) {
            sol[i]=sol[i]-i;
        }
    }

    return sol;
}