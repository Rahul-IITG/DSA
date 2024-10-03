#include <vector>

using namespace std;

// This is an input class. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList* next;

    LinkedList(int value) {
        this->value = value;
        next = nullptr;
    }
};

LinkedList* mergeLinkedLists(LinkedList* headOne, LinkedList* headTwo) {
    LinkedList* head;
    LinkedList* tail;

    if (headOne->value<headTwo->value) {
        head=headOne;
        tail=head;
        headOne=headOne->next;
    }
    else {
        head=headTwo;
        tail=head;
        headTwo=headTwo->next;
    }

    while (headOne!=nullptr&&headTwo!=nullptr) {
        if (headOne->value<headTwo->value) {
            tail->next=headOne;
            tail=tail->next;
            headOne=headOne->next;
        }
        else {
            tail->next=headTwo;
            tail=tail->next;
            headTwo=headTwo->next;
        }
    }

    while (headOne!=nullptr) {
        tail->next=headOne;
        tail=tail->next;
        headOne=headOne->next;
    }

    while (headTwo!=nullptr) {
        tail->next=headTwo;
        tail=tail->next;
        headTwo=headTwo->next;
    }

    return head;
}