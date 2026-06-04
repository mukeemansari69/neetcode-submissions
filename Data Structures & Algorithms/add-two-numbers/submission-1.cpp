class Solution {
public:
    string helper(ListNode* head) {
        string s = "";

        while (head) {
            s += to_string(head->val);
            head = head->next;
        }

        reverse(s.begin(), s.end());
        return s;
    }

    string addStrings(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        string ans = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            ans += (sum % 10) + '0';
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    ListNode* linked(string s) {
        ListNode* head = new ListNode(s[0] - '0');
        ListNode* temp = head;

        for (int i = 1; i < s.size(); i++) {
            temp->next = new ListNode(s[i] - '0');
            temp = temp->next;
        }

        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s = helper(l1);
        string t = helper(l2);

        string sum = addStrings(s, t);

        reverse(sum.begin(), sum.end());

        return linked(sum);
    }
};