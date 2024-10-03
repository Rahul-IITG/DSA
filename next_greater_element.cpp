#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> array) {
    int s=array.size();

    for (int i=0;i<s;i++) {
        array.push_back(array[i]);
    }

    stack<int> st;
    vector<int> sol;

    for (int i=2*s-1;i>=0;i--) {
        if (st.empty()) {
            sol.push_back(-1);
            st.push(array[i]);
            continue;
        }
        if (st.top()>array[i]) {
            sol.push_back(st.top());
            st.push(array[i]);
            continue;
        }

        while (!st.empty()&&st.top()<=array[i]) {
            st.pop();
        }
        if (st.empty()) {
            sol.push_back(-1);
            st.push(array[i]);
            continue;
        }
        if (st.top()>array[i]) {
            sol.push_back(st.top());
            st.push(array[i]);
            continue;
        }
    }

    vector<int> correctedSol;

    for (int i=2*s-1;i>=s;i--) {
        correctedSol.push_back(sol[i]);
    }

    return correctedSol;
}
