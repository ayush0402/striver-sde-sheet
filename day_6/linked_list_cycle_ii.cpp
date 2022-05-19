/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    Using Floyd's cycle algorithm to find the node where
    fast and slow pointers first collide.
    And then iterating slow pointer from that point while also
    iterating a slow pointer from the head.
    The new point of collision is the answer.

    The question "Find the Duplicate Number" (https://leetcode.com/problems/find-the-duplicate-number/)
    also uses the same algorithm for its solution.
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        do {
            fast = fast->next->next;
            slow = slow->next;
        }
        while (fast != slow && fast != NULL && fast->next != NULL);

        if (fast != slow) {
            return NULL;
        }

        fast = head;

        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;

    }
};
