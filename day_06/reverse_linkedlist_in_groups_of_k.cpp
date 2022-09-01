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

// Reference: Fraz's YouTube video.

class Solution {
public:
    void reverse(ListNode* start, ListNode* end) {
        ListNode* prev = NULL, * curr = start, * nxt = start->next;
        while (prev != end) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* beforeStart = dummy;
        ListNode* end = head;
        int i = 0;
        while (end != NULL) {
            i++;
            if (i % k == 0) {
                ListNode* temp = end->next;
                ListNode* start = beforeStart->next;
                reverse(start, end);
                beforeStart->next = end;
                start->next = temp;
                beforeStart = start;
                end = temp;
            }
            else end = end->next;
        }
        return dummy->next;
    }
};
