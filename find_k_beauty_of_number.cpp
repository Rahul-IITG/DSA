#include <string>
using namespace std;

int divisorSubstrings(int num, int k) {
    string str=to_string(num);
    int s=str.size();

    if (k>s) {
        return 0;
    }

    int no=0;

    int left=0;
    int right=0;
    string curr="";

    while (right<s) {
        curr.push_back(str[right]);

        if (right-left+1==k) {
            int number=stoi(curr);

            if (number!=0&&num%number==0) {
                no++;
            }

            curr.erase(curr.begin());
            left++;
        }

        right++;
    }

    return no;
}