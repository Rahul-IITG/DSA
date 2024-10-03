using namespace std;

class LinkedList {
public:
    int value;
    LinkedList* next;

    LinkedList(int value) {
        this->value = value;
        next = nullptr;
    }
};

void traverse(LinkedList* head, LinkedList* &newHead, int k, LinkedList* &tail) {
    if (head==nullptr) {
        return;
    }

    traverse(head,newHead,k,tail);
    if (tail==nullptr) {
        tail=head;
    }
    k--;

    if (k==0) {
        newHead=head->next;
        head->next=nullptr;
    }

    return;
}

LinkedList* shiftLinkedList(LinkedList* head, int k) {
    LinkedList* newHead;
    newHead=head;

    int s=0;

    while (newHead!=nullptr) {
        s++;
        newHead=newHead->next;
    }

    k=k%s;

    if (k<0) {
        k=s-k;
    }

    LinkedList* tail=nullptr;
    traverse(head,newHead,k,tail);
    tail->next=head;
    return newHead;
}
