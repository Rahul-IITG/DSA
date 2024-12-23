#include <vector>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int s=deck.size();
    vector<int> sol(s,0);
    int index=0;
    bool skip=false;
    int i=0;

    sort(deck.begin(),deck.end());

    while (i<s) {
        if (sol[index]==0) {
            if (!skip) {
                sol[index]=deck[i];
                i++;
            }

            skip=!skip;
        }

        index=(index+1)%s;
    }

    return sol;
}