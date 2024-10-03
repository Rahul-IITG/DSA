#include <vector>
using namespace std;

void correct(vector<int> scores, int start, int index, vector<int> rewards, int s) {
    for (int i=index-1;i>=start;i--) {
        if (rewards[i]==rewards[i+1]) {
            rewards[i]++;
        }
    }
}

int minRewards(vector<int> scores) {
    int s=scores.size();
    vector<int> rewards(s,1);
    int start=0;

    for (int i=1;i<s;i++) {
        if (scores[i-1]==scores[i]) {
            rewards[i]=rewards[i-1];
        }
        if (scores[i-1]<scores[i]) {
            rewards[i]=rewards[i-1]+1;
            start=i;
        }
        if (scores[i-1]>scores[i]) {
            if (rewards[i-1]>1) {
                rewards[i]=1;
                continue;
            }

            correct(scores,start,i,rewards,s);
        }
    }

    int sum=0;

    for (int i=0;i<s;i++) {
        sum=sum+rewards[i];
    }

    return sum;
}
