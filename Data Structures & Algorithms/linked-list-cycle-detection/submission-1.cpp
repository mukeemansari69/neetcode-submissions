/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode * s=head;
        ListNode * f=head;
       while(f->next !=NULL && f->next->next!=NULL){
          f=f->next->next;
          s=s->next;
          if(s==f) return true;
       }
        return false;
    }
};
