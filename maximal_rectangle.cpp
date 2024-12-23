#include <vector>
using namespace std;

vector<int> getLeft(int s, vector<int> heights) {
    vector<int> left(s);
    stack<int> st;
    int i=0;

    while (i<s) {
        if (st.empty()) {
            left[i]=-1;
            st.push(i);
            i++;
            continue;
        }

        if (heights[st.top()]<heights[i]) {
            left[i]=st.top();
            st.push(i);
            i++;
            continue;
        }

        while (!st.empty()&&heights[st.top()]>=heights[i]) {
            st.pop();
        }

        if (st.empty()) {
            left[i]=-1;
            st.push(i);
            i++;
        }
        else {
            left[i]=st.top();
            st.push(i);
            i++;
        }
    }

    return left;
}

vector<int> getRight(int s, vector<int> heights) {
    vector<int> right(s);
    stack<int> st;
    int i=s-1;

    while (i>=0) {
        if (st.empty()) {
            right[i]=-1;
            st.push(i);
            i--;
            continue;
        }

        if (heights[st.top()]<heights[i]) {
            right[i]=st.top();
            st.push(i);
            i--;
            continue;
        }

        while (!st.empty()&&heights[st.top()]>=heights[i]) {
            st.pop();
        }

        if (st.empty()) {
            right[i]=-1;
            st.push(i);
            i--;
        }
        else {
            right[i]=st.top();
            st.push(i);
            i--;
        }
    }

    return right;
}

int largestRectangleArea(vector<int>& heights) {
    int s=heights.size();
    if (s==1) {
        return heights[0];
    }
    vector<int> left;
    vector<int> right;
    left=getLeft(s,heights);
    right=getRight(s,heights);

    int area=0;

    for (int i=0;i<s;i++) {
        int li=(left[i]==-1 ? -1 : left[i]);
        int ri=(right[i]==-1 ? s : right[i]);
        int curr=heights[i]*(ri-li-1);
        area=max(area,curr);
    }

    return area;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();

    vector<int> dp(m,0);
    int sol=INT_MIN;

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (matrix[i][j]==1) {
                dp[j]=dp[j]+1;
            }
            else {
                dp[j]=0;
            }
        }

        sol=min(sol,largestRectangleArea(dp));
    }

    return sol;
}