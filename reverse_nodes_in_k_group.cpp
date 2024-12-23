using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
   if (head==nullptr||k==0||k==1) {
      return head;
   }

   ListNode* dummy=new ListNode(0);
   dummy->next=head;
   ListNode* prev=dummy;
   ListNode* curr=dummy;
   ListNode* nex=dummy;

   int size=0;

   while (curr->next!=nullptr) {
      size++;
   }

   int s=k;

   while (size>=k) {
      curr=prev->next;
      nex=curr->next;
      k=s;

      while (k!=1) {
         curr->next=nex->next;
         nex->next=prev->next;
         prev->next=nex;
         nex=curr->next;
         k--;
      }

      prev=curr;
      size=size-k;
   }

   return dummy->next;
}