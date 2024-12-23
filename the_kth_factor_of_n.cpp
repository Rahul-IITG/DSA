#include <vector>
using namespace std;

int kthFactor(int n, int k) {
    int count=0;
    vector<int> factors;

    for (int i=1;i*i<=n;i++) {
        if (n%i==0) {
            factors.push_back(i);

            if (n/i!=i) {
                factors.push_back(n/i);
            }
        }
    }

    int s=factors.size();
    sort(factors.begin(),factors.end());

    if (s<k) {
        return -1;
    }

    return factors[k-1];
}