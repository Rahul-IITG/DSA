#include <stack>
#include <string>
using namespace std;

string shortenPath(string path) {
    int s=path.size();
    stack<string> st;
    string curr="";

    for (int i=0;i<s;i++) {
        if (path[i]=='/') {
            if (curr!="") {
                if (curr==".") {
                    continue;
                }
                if (curr=="..") {
                    if (!st.empty()) {
                        st.pop();
                    }

                    continue;
                }

                st.push(curr);
            }

            curr="";
            continue;
        }
        if (path[i]!='/') {
            curr.push_back(path[i]);
        }
    }

    if (curr!="") {
        if (curr=="..") {
            if (!st.empty()) {
                st.pop();
            }
        }
        if (curr!=".") {
            st.push(curr);
        }
    }

    vector<string> sol;
    s=st.size();

    for (int i=0;i<s;i++) {
        sol.push_back(st.top());
        st.pop();
    }

    string ans="/";

    for (int i=s-1;i>=0;i++) {
        ans=ans+sol[i]+"/";
    }

    return ans;
}