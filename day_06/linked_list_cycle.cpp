/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    Naive Approach

    Iterate through the nodes and keep adding them to a
    hash table, in case of it already exists there, there
    exists a cycle.

    Time Complexity : O(n)
    Space Complexity : O(n)
*/

/*
    Optimised Approach

    Using Floyd's cycle detection algorithm.
    Time Complexity : O(n)
    Space Complexity : O(1)
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {

        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return false;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        do {
            fast = fast->next->next;
            slow = slow->next;
        }
        while (fast != slow && fast != NULL && fast->next != NULL);

        if (fast == slow) {
            return true;
        }
        return false;
    }
};
