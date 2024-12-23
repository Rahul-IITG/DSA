#include <vector>
using namespace std;

class ProductOfNumbers {
public:
    int s=0;
    vector<int> nums;
    int prefix=1;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        prefix=prefix*num;
        nums.push_back(prefix);
        s++;
    }
    
    int getProduct(int k) {
        if (k==s) {
            return nums[s-1];
        }
        else {
            return nums[s-1]/nums[s-k];
        }
    }
};