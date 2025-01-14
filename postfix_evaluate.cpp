#include <stack>
#include <vector>
using namespace std;

int evalRPN(vector<string>& tokens) {
    int s=tokens.size();
    stack<int> st;

    for (int i=0;i<s;i++) {
        if (tokens[i]=="*"||tokens[i]=="/"||tokens[i]=="+"||tokens[i]=="-") {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();

            if (tokens[i]=="*") {
                st.push(a*b);
            }
            if (tokens[i]=="/") {
                st.push(b/a);
            }
            if (tokens[i]=="+") {
                st.push(a+b);
            }
            if (tokens[i]=="-") {
                st.push(b-a);
            }

            continue;
        }

        st.push(stoi(tokens[i]));
    }

    return st.top();
}