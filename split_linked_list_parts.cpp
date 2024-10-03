#include <vector>

using namespace std;

struct ListNode {
         int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void traverse(ListNode* head, ListNode* tail, vector<ListNode*> &sol, int r, int k, int count, int s) {
    if (head==NULL) {
        return;
    }

    if (tail==NULL) {
        sol.push_back(head);
        return;
    }

    if (count==s/k) {
        if (r>0) {
            tail=tail->next;
            r--;
        }

        ListNode* nextHead=tail->next;
        tail->next=NULL;
        sol.push_back(head);
        tail=nextHead;
        traverse(nextHead, tail, sol, r, k, 1, s);
        return;
    }

    tail=tail->next;
    count++;
    traverse(head, tail, sol, r, k, count, s);
}

vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int s=0;
    ListNode* tail=head;

    while (tail!=NULL) {
        tail=tail->next;
        s++;
    }

    vector<ListNode*> sol;


    if (s<=k) {
        for (int i=0;i<s;i++) {
            sol.push_back(new ListNode(head->val));
            head=head->next;
        }

        while (k-s) {
            sol.push_back(NULL);
            s++;
        }
    }

    int r=s%k;
    tail=head;

    traverse(head,tail,sol,r,k,1,s);

    return sol;
}