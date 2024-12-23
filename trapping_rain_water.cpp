#include <stack>
#include <vector>

using namespace std;

vector<int> getLeft(int s, vector<int> height, vector<int> &left) {
    stack<int> st;

    for (int i=s-1;i>=0;i--) {
        while (!st.empty()&&height[st.top()]<=height[i]) {
            st.pop();
        }

        if (st.empty()) {
            st.push(i);
            left.push_back(-1);
            continue;
        }

        left.push_back(st.top());

    }
}

vector<int> getRight(int s, vector<int> height, vector<int> &right) {

}

int trap(vector<int>& height) {
    int s=height.size();
    vector<int> left=getLeft(s,height,left);
    vector<int> right=getRight(s,height,right);

    int water=0;

    for ()
}
