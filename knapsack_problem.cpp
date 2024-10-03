#include <vector>
using namespace std;

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
    int s=items.size();

    vector<vector<int>> dp(s+1,vector<int>(capacity+1,-1));
    vector<vector<vector<int>>> sol(s+1,vector<vector<int>>(capacity+1));

    for (int i=0;i<=s;i++) {
        dp[i][0]=0;
    }
    for (int i=0;i<=capacity;i++) {
        dp[0][i]=0;
    }

    for (int i=1;i<=s;i++) {
        for (int j=1;j<=capacity;j++) {
            if (items[i-1][1]<=j) {
                dp[i][j]=max(items[i-1][0]+dp[i-1][j-items[i-1][1]], dp[i-1][j]);
                if (items[i-1][0]+dp[i-1][j-items[i-1][1]] > dp[i-1][j]) {
                    vector<int> curr=sol[i-1][j-items[i-1][1]];
                    curr.push_back(i-1);
                    sol[i][j]=curr;
                    continue;
                }

                sol[i][j]=sol[i-1][j];
            }
            else {
                dp[i][j]=dp[i-1][j];
                sol[i][j]=sol[i-1][j];
            }
        }
    }

    vector<vector<int>> ans;
    vector<int> valArr;
    valArr.push_back(dp[s][capacity]);
    ans.push_back(valArr);
    ans.push_back(sol[s][capacity]);
    return ans;
}
