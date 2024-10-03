string tournamentWinner(vector<vector<string>> competitions, vector<int> results) {
    int s = results.size();
    unordered_map<int,int> ump;

    for (int i=0;i<s;i++) {
        if (results[i] == 0) {
            ump[competitions[i][1]] = ump[competitions[i][1]]+3;
            continue;
        }

        ump[competitions[i][0]] = ump[competitions[i][0]]+3;
    }

    unordered_map<int,int>::iterator itr;
    int sol = -1;
    string ans;

    for (auto &itr : ump) {
        if (itr.second > sol) {
            sol = itr.second;
            ans=itr.first;
        }
    } 

    return ans;
}