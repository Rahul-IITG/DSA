#include <cstddef>

class LinkedList {
public:
    int value;
    LinkedList* next = nullptr;

    LinkedList(int value) { this->value = value; }
};

LinkedList* middleNode(LinkedList* linkedList) {
    if (linkedList == NULL) {
        return NULL;
    }

    int s=0;
    LinkedList* head=linkedList;
    LinkedList* tail=linkedList;

    while (tail != NULL) {
        tail=tail->next;
        s++;
    }

    int index=s/2+1;

    while (--index>0) {
        head=head->next;
    }

    return head;
}