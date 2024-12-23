#include <queue>
#include <stack>
#include <string>
using namespace std;

string infixToPostfix(string str) {
    int s=str.size();
    unordered_map<char,int> umap;
    umap['+']=2;
    umap['-']=2;
    umap['*']=1;
    umap['/']=1;
    umap['(']=3;

    string postfix="";
    stack<char> st;

    for (int i=0;i<s;i++) {
        if (str[i]==' ') {
            continue;
        }
        if (str[i]!='+'&&str[i]!='-'&&str[i]!='*'&&str[i]!='/'&&str[i]!='('&&str[i]!=')') {
            postfix.push_back(str[i]);
            continue;
        }

        if (st.empty()||str[i]=='(') {
            st.push(str[i]);
            continue;
        }

        if (str[i]==')') {
            while (st.top()!='(') {
                postfix.push_back(st.top());
                st.pop();
            }

            st.pop();
            continue;
        }

        if (umap[str[i]]<umap[st.top()]) {
            st.push(str[i]);
            continue;
        }

        while (!st.empty()&&umap[str[i]]>=umap[st.top()]) {
            postfix.push_back(st.top());
            st.pop();
        }

        st.push(str[i]);
    }

    while (!st.empty()) {
        postfix.push_back(st.top());
        st.pop();
    }

    return postfix;
}