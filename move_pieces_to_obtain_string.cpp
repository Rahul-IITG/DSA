#include <string>
using namespace std;

void swap(int i, int index, string &start) {
    char temp=start[index];
    start[index]=start[i];
    start[i]=temp;

    return;
}

bool move(int index, int s, string start, string target) {
    if (target[index]=='L'&&start[index]=='R') {
        return false;
    }
    if (target[index]=='R'&&start[index]=='L') {
        return false;
    }
    if (target[index]=='_'&&start[index]=='L') {
        return false;
    }
    if (target[index]=='R'&&start[index]=='_') {
        return false;
    }

    if (target[index]=='L'&&start[index]=='_') {
        for (int i=index+1;i<s;i++) {
            if (start[i]=='L') {
                swap(i,index,start);
                return true;
            }
            if (start[i]=='R') {
                return false;
            }
        }

        return false;
    }
    if (target[index]=='_'&&start[index]=='R') {
        for (int i=index+1;i<s;i++) {
            if (start[i]=='_') {
                swap(i,index,start);
                return true;
            }
            if (start[i]=='L') {
                return false;
            }
        }

        return false;
    }
}

bool canChange(string start, string target) {
    int s=start.size();

    if (s!=target.size()) {
        return false;
    }

    int i=0;
    int j=0;

    while (i<s||j<s) {
        while (i<s&&start[i]=='_') {
            i++;
        }
        while (j<s&&target[j]=='_') {
            j++;
        }

        if (start[i]!=target[j]) {
            return false;
        }

        if (start[i]=='L') {
            if (j>i) {
                return false;
            }
        }
        if (start[i]=='R') {
            if (j<i) {
                return false;
            }
        }

        i++;
        j++;
    }

    return true;
}