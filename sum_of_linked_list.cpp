using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList* next = nullptr;

    LinkedList(int value) { this->value = value; }
};

LinkedList* add(LinkedList* one, LinkedList* two, int carry) {
    LinkedList* head;

    if (one!=nullptr&&two!=nullptr) {
        head=new LinkedList((one->value+two->value+carry)%10);
        head->next=add(one->next,two->next,(one->value+two->value+carry)/10);
        return head;
    }
    if (one!=nullptr) {
        head=new LinkedList((one->value+carry)%10);
        head->next=add(one->next,two,(one->value+carry)/10);
        return head;
    }
    if (two!=nullptr) {
        head=new LinkedList((two->value+carry)%10);
        head->next=add(one,two->next,(two->value+carry)/10);
        return head;
    }
    if (carry==1) {
        head=new LinkedList(1);
        return head;
    }

    return nullptr;
}

LinkedList* sumOfLinkedLists(
  LinkedList* linkedListOne, LinkedList* linkedListTwo) {
    return add(linkedListOne,linkedListTwo,0);
}