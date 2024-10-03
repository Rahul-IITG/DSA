#include <vector>
using namespace std;

int validStartingCity(vector<int> distances, vector<int> fuel, int mpg) {
    int s=distances.size();
    int tank=0;
    int sol=0;

    for (int i=0;i<s;i++) {
        if (tank<0) {
            tank=tank+fuel[i]*mpg;

            if (tank>0) {
                sol=i;
            }

            tank=tank-distances[i];
            continue;
        }

        tank=tank+fuel[i]*mpg;
        tank=tank-distances[i];
    }

    return sol;
}
