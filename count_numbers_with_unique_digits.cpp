using namespace std;

int countNumbersWithUniqueDigits(int n) {
    if (n==0) {
        return 1;
    }

    int sol=0;
    int product=9;

    for (int i=2;i<=n;i++) {
        sol=sol+product*(11-i);
        product=product*(11-i);
    }

    return sol;
}