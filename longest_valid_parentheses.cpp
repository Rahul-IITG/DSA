#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(string str) {
    int s=str.size();

    if (s==0||s==1) {
        return 0;
    }

    stack<int> st;
    int i=0;

    while (i<s) {
        if (st.empty()) {
            st.push(i);
            i++;
            continue;
        }

        if (str[st.top()]=='('&&str[i]==')') {
            st.pop();
            i++;
        }
        else {
            st.push(i);
            i++;
        }
    }

    int end=s-1;

    if (st.empty()) {
        return s;
    }

    int sol=INT_MIN;

    while (!st.empty()) {
        int curr=st.top();
        st.pop();

        sol=max(sol,end-curr);
        end=curr;
    }

    sol=max(sol,end);

    return sol;
}