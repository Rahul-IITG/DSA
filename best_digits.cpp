#include <string>
using namespace std;

string bestDigits(string number, int numDigits) {
    int s=number.size();

    if (numDigits==s) {
        return "";
    }



    return number.substr(0,number.size()-numDigits);
}
