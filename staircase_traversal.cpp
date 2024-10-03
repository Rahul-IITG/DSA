#include <vector>
using namespace std;

int staircaseTraversal(int height, int maxSteps) {
    vector<int> steps(height+1,0);
    steps[0]=1;

    for (int i=1;i<=height;i++) {

        for (int j=1;j<=maxSteps;j++) {
            if (i-j<0) {
                break;
            }

            steps[i]=steps[i]+steps[i-j];
        }
    }

    return steps[height];
}
