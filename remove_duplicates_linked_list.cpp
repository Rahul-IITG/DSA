using namespace std;

class LinkedList {
public:
    int value;
    LinkedList* next = nullptr;

    LinkedList(int value) { this->value = value; }
};

LinkedList* removeDuplicatesFromLinkedList(LinkedList* linkedList) {
    if (linkedList == NULL) {
        return NULL;
    }

    LinkedList* head=linkedList;
    LinkedList* tail=linkedList;

    while (tail->next != NULL) {
        if (tail->value != tail->next->value) {
            tail=tail->next;
            continue;
        }

        tail->next=tail->next->next;
    }

    return head;
}
