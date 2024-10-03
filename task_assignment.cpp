#include <vector>
using namespace std;

bool comp_fun(vector<int> &a, vector<int> &b) {
    return a[0]<b[0];
}

vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
    vector<vector<int>> task;

    for (int i=0;i<2*k;i++) {
        vector<int> curr;
        curr.push_back(tasks[i]);
        curr.push_back(i);
        task.push_back(curr);
    }

    sort(task.begin(),task.end(),comp_fun);
    vector<vector<int>> sol;

    for (int i=0;i<k;i++) {
        vector<int> curr;
        curr.push_back(i);
        curr.push_back(2*k-1-i);
        sol.push_back(curr);
    }

    return sol;
}