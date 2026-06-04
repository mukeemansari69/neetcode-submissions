
class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
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
     
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if (lists.size() == 0)
            return NULL;
        while (lists.size() > 1) {
            ListNode* a = lists[lists.size() - 1];
            lists.pop_back();
            ListNode* b = lists[lists.size() - 1];
            lists.pop_back();
            ListNode* c = merge(a, b);
            lists.push_back(c);
        }
        return lists[0];
    }
};
