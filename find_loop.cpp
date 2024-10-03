#include <vector>
using namespace std;

class LinkedList {
public:
    int value;
    LinkedList* next;

    LinkedList(int value);
};

LinkedList* findLoop(LinkedList* head) {
    LinkedList* slow;
    LinkedList* fast;
    slow=head;
    fast=head->next;

    while (slow!=fast) {
        slow=slow->next;
        fast=fast->next->next;
    }

    slow=head;

    while (slow!=fast) {
        slow=slow->next;
        fast=fast->next;
    }

    return slow;
}
