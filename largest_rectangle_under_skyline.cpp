#include <vector>
#include <stack>
using namespace std;

void smallestToLeft(vector<int> buildings, vector<int> &left) {
    int s=buildings.size();
    stack<int> st;

    for (int i=0;i<s;i++) {
        if (st.empty()) {
            left.push_back(-1);
            st.push(i);
            continue;
        }

        while (!st.empty()&&buildings[st.top()]>=buildings[i]) {
            st.pop();
        }
        if (st.empty()) {
            left.push_back(-1);
            st.push(i);
            continue;
        }

        left.push_back(st.top());
        st.push(i);
    }

    return;
}

void smallestToRight(vector<int> buildings, vector<int> &right) {
    int s=buildings.size();
    stack<int> st;

    for (int i=s-1;i>=0;i++) {
        if (st.empty()) {
            right.push_back(-1);
            st.push(i);
            continue;
        }

        while (!st.empty()&&buildings[st.top()]>=buildings[i]) {
            st.pop();
        }
        if (st.empty()) {
            right.push_back(-1);
            st.push(i);
            continue;
        }

        right.push_back(st.top());
        st.push(i);
    }

    reverse(right.begin(),right.end());
    return;
}

int largestRectangleUnderSkyline(vector<int> buildings) {
    int s=buildings.size();
    vector<int> left;
    vector<int> right;
    smallestToLeft(buildings,left);
    smallestToRight(buildings,right);

    int area=INT_MIN;
    int length;

    for (int i=0;i<s;i++) {
        if (left[i]==-1&&right[i]==-1) {
            length=s;
        }
        else if (left[i]==-1) {
            length=right[i];
        }
        else if (right[i]==-1) {
            length=s-left[i]-1;
        }
        else {
            length=right[i]-left[i]-1;
        }

        int curr=buildings[i]*length;
        area=max(area,curr);
    }

    return area;
}