int nonConstructibleChange(vector<int> coins) {
    int s = coins.size();
    sort(coins.begin(), coins.end());
    int sol=0;

    for (int i=0;i<s;i++) {
        if (coins[i] > sol+1) {
            break;
        }

        sol = sol + coins[i];
    }

    return sol+1;
}