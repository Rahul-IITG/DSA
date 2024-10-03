vector<int> sortedSquaredArray(vector<int> array) {
    int s = array.size();
    vector<int> sol;
    vector<int> pos;
    vector<int> neg;

    for (int i=0;i<s;i++) {
        if (array[i] < 0) {
            neg.push_back(array[i] * array[i]);
            continue;
        }

        pos.push_back(array[i] * array[i]);
    }

    int ns = neg.size();
    int ps = pos.size();
    int i=0;
    int j=ns-1;

    while (i<ps && j >= 0) {
        if (pos[i] < neg[j]) {
            sol.push_back(pos[i]);
            i++;
            continue;
        }

        sol.push_back(neg[j]);
        j--;
    }

    while (i<ps) {
        sol.push_back(pos[i]);
        i++;
    }
    while (j >= 0) {
        sol.push_back(neg[j]);
        j--;
    }

    return sol;
}