#include <stack>
#include <vector>
using namespace std;

int sumSubarrayMins(vector<int>& arr) {
    int MOD = 1000000007;
    int s=arr.size();
    int sum=0;
    stack<int> st;

    for (int i=0;i<=s;i++) {
        while (!st.empty()&&(i==s||arr[st.top()]>=arr[i])) {
            int curr=st.top();
            st.pop();
            int left=st.empty() ? -1 : st.top();
            int right=i;

            int count=(curr-left)*(right-curr)%MOD;
            sum=(sum+count*arr[i])%MOD;
        }

        st.push(i);
    }

    return sum;
}