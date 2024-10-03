#include <vector>
using namespace std;

class LinkedList {
public:
    int value;
    LinkedList* next;

    LinkedList(int value);
    void addMany(vector<int> values);
    vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList* head, int k) {
    int s=0;
    LinkedList* tail;
    tail=head;

    while (tail!=nullptr) {
        s++;
        tail=tail->next;
    }

    k=s-k;
    tail=head;

    if (k==0) {
        head=(head->next);
    }

    while (k>0) {
        if (k==1) {
            tail=tail->next->next;
            break;
        }

        tail=tail->next;
        k--;
    }
}
