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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* newhead = new ListNode(-1);
        ListNode* t = newhead;

        ListNode* a = list1;
        ListNode* b = list2;

        while(a != NULL && b != NULL) {

            if(a->val <= b->val) {
                t->next = a;
                a = a->next;
            }
            else {
                t->next = b;
                b = b->next;
            }

            t = t->next;
        }

        if(a == NULL)
            t->next = b;
        else
            t->next = a;

        return newhead->next;
    }
};
