

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        ListNode * fast=head;
        ListNode * slow=head;
       
        for(int i=1;i<n;i++){
            fast=fast->next;
        }
         if(fast->next==NULL) return  head->next;
        while(fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
       slow->next=slow->next->next;
       return head;
    }
};
