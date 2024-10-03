#include <stack>
#include <string>
using namespace std;

bool balancedBrackets(string str) {
    stack<char> st;
    int i=0;
    int s=str.length();

    while (i<s) {
        if (st.empty()) {
            if (str[i]==']'||str[i]=='}'||str[i]==')') {
                return false;
            }
            else {
                st.push(str[i]);
            }

            i++;
            continue;
        }

        if (str[i]==')'&&st.top()=='(') {
            st.pop();
            i++;
            continue;
        }
        if (str[i]=='}'&&st.top()=='{') {
            st.pop();
            i++;
            continue;
        }
        if (str[i]==']'&&st.top()=='[') {
            st.pop();
            i++;
            continue;
        }
        if (str[i]==')'||str[i]=='}'||str[i]==']') {
            return false;
        }

        st.push(str[i]);
        i++;
    }

    if (st.empty()) {
        return true;
    }

    return false;
}
