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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* last = ans;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int sum = 0;
            if (l1 != NULL)sum += l1->val;
            if (l2 != NULL)sum += l2->val;
            sum += carry;
            carry = 0;
            if (sum > 9) {
                carry = 1;
                sum -= 10;
            }
            ListNode* n = new ListNode(sum);
            last->next = n;
            last = n;
            if (l1 != NULL)l1 = l1->next;
            if (l2 != NULL)l2 = l2->next;
        }

        if (carry) {
            last->next = new ListNode(1);
        }

        return ans->next;
    }
};
