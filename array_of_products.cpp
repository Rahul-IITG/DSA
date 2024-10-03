#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
    int s=array.size();
    int count=0;
    vector<int> sol;
    int product=1;

    for (int i=0;i<s;i++) {
        if (array[i]==0) {
            count++;
            continue;
        }

        product=product*array[i];
    }

    if (count>1) {
        return vector<int> (s,0);
    }

    for (int i=0;i<s;i++) {
        if (count==1&&array[i]==0) {
            sol.push_back(product);
            continue;
        }
        if (count==1) {
            sol.push_back(0);
            continue;
        }

        sol.push_back(product/array[i]);
    }

    return sol;
}
