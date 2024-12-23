#include <vector>
using namespace std;

bool comp_func(vector<int> &a, vector<int> &b) {
    return a[1]<b[1];
}

int findLastNonConflictingJob(vector<vector<int>>& jobs, int index) {
    int low = 0, high = index - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (jobs[mid][1] <= jobs[index][0]) {
            if (jobs[mid + 1][1] <= jobs[index][0]) {
                low = mid + 1; // Move to the right
            } else {
                return mid; // Found the last non-conflicting job
            }
        } else {
            high = mid - 1; // Move to the left
        }
    }
    return -1; // No non-conflicting job found
}

int recur(vector<vector<int>> jobs, int n) {
    vector<int> dp(n);
    dp[0] = jobs[0][2]; // Profit of the first job

    for (int i = 1; i < n; i++) {
        // Include the current job's profit
        int includeProfit = jobs[i][2];
        // Find the last non-conflicting job
        int l = findLastNonConflictingJob(jobs, i);
        if (l != -1) {
            includeProfit += dp[l]; // Add the profit of last non-conflicting job
        }
        // Store the maximum profit by either including or excluding the job
        dp[i] = max(includeProfit, dp[i - 1]);
    }

    return dp[n - 1];
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int s=profit.size();

    vector<vector<int>> jobs;

    for (int i=0;i<s;i++) {
        jobs.push_back({startTime[i],endTime[i],profit[i]});
    }

    sort(jobs.begin(),jobs.end(),comp_func);
    return recur(jobs,s);
}