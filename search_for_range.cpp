#include <vector>
using namespace std;

void correctSol(int left, int right, vector<int> array, vector<int> &sol, int target) {
    while (left<=right) {
        int middle=(left+right)/2;

        if (target<array[middle]) {
            right=middle-1;
            continue;
        }
        if (array[middle]<target) {
            left=middle+1;
            continue;
        }
        if (array[middle]==target) {
            if (middle<sol[0]) {
                sol[0]=middle;
            }
            if (middle>sol[1]) {
                sol[1]=middle;
            }
            correctSol(left,middle-1,array,sol,target);
            correctSol(middle+1,right,array,sol,target);
        }
    }

    return;
}

vector<int> searchForRange(vector<int> array, int target) {
    int s=array.size();

    int left=0;
    int right=s-1;
    vector<int> sol(2,-1);

    while (left<=right) {
        int middle=(left+right)/2;

        if (target<array[middle]) {
            right=middle-1;
            continue;
        }
        if (array[middle]<target) {
            left=middle+1;
            continue;
        }
        if (array[middle]==target) {
            sol[0]=middle;
            sol[1]=middle;
            correctSol(left,middle-1,array,sol,target);
            correctSol(middle+1,right,array,sol,target);
        }
    }

    return sol;
}
