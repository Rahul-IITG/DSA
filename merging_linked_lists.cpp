#include <unordered_map>
using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList* next = nullptr;

    LinkedList(int value) { this->value = value; }
};

LinkedList* mergingLinkedLists(
  LinkedList* linkedListOne, LinkedList* linkedListTwo) {
    unordered_map<LinkedList*,int> umap;

    while (linkedListOne!=nullptr) {
        umap[linkedListOne]++;
        linkedListOne=linkedListOne->next;
    }

    while (linkedListTwo!=nullptr) {
        if (umap[linkedListTwo]==1) {
            return linkedListTwo;
        }

        linkedListTwo=linkedListTwo->next;
    }

    return nullptr;
}
