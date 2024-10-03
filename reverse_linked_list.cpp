using namespace std;

class LinkedList {
public:
    int value;
    LinkedList* next;

    LinkedList(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

void reverseLinkedList(LinkedList* head, LinkedList* newHead, LinkedList* tail) {
    if (head==nullptr) {
        return;
    }

    reverseLinkedList(head->next,newHead);
    if (newHead==nullptr) {
        newHead=head;
        tail=newHead;
        return;
    }

    tail->next=head;
    tail=tail->next;
    return;
}

LinkedList* reverseLinkedList(LinkedList* head) {
    LinkedList* newHead=nullptr;
    LinkedList* tail;
    reverseLinkedList(head,newHead,tail);
    tail->next=nullptr;
    return newHead;
}
