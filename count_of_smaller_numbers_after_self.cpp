#include <stack>
#include <vector>
using namespace std;

vector<int> countSmaller(vector<int>& nums) {
    int s=nums.size();
    stack<int> st;
    vector<int> sol(s,0);

    for (int i=s-1;i>=0;i++) {
        while (!st.empty()&&st.top()<nums[i]) {
            st.pop();
        }

        sol[i]=s-1-i-st.size();
        st.push(nums[i]);
    }

    return sol;
}