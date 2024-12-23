using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode* first=head;
    ListNode* second=head;

    while (true) {
        if (second->next==nullptr||second->next->next==nullptr) {
            return nullptr;
        }

        first=first->next;
        second=second->next->next;

        if (first==second) {
            first=head;
            break;
        }
    }

    while (true) {
        if (first==second) {
            return first;
        }

        first=first->next;
        second=second->next;
    }

    return nullptr;
}