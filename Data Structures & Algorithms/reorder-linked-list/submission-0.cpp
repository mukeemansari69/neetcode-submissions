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
    ListNode * reverse(ListNode * head){
        
        if (head==NULL or head->next==NULL) return head;
        ListNode * curr=head;
        ListNode * Next=head;
        ListNode * prev=NULL;
        while(curr){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode * s=head;
        ListNode * f=head;
        while(f->next!=NULL && f->next->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        ListNode * Newhead=reverse(s->next);
        s->next=NULL;
        ListNode * temp=new ListNode (-1);
        ListNode * a=Newhead;
        ListNode * b=head;
        ListNode *c=temp;
        while(a && b){
            c->next=b;
            b=b->next;
            c=c->next;
            c->next=a;
            a=a->next;
            c=c->next;
            
        }
         if(b) c->next=b;
        if(a) c->next=a;

        head = temp->next; 
        
    }
};
