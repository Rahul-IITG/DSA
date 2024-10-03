#include <vector>
using namespace std;

void permutate(int index, vector<int> array, vector<int> curr, vector<vector<int>> &sol, int size, int k, int s) {
    if (k==size) {
        sol.push_back(curr);
        return;
    }

    for (int i=index+1;i<s;i++) {
        vector<int> cc=curr;
        cc.push_back(array[i]);
        permutate(i,array,cc,sol,size,k+1,s);
    }

    return;
}

vector<vector<int>> powerset(vector<int> array) {
    int s=array.size();
    vector<vector<int>> sol;
    int size=1;
    vector<int> empty;
    sol.push_back(empty);

    while (size<s) {
        for (int i=0;i<s;i++) {
            vector<int> curr;
            curr.push_back(array[i]);
            permutate(i,array,curr,sol,size,1,s);
        }

        size++;
    }

    sol.push_back(array);
    return sol;
}
