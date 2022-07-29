/**
 * [Palindrome Linked List]
 *
 * Naive Approach:
 * The naive approach can be to store all the values in the linked list into
 * some array or vector by iterating from the head and then simply checking if that
 * array is a palindrome or not.
 *
 * Optimised Approach:
 * This includes the idea of finding the middle of the linked list and then reversing
 * the right half. Then simply iterating the left and right halves of the linked list
 * to check if they are equal or not.
 * The right half of the array can be reversed again to bring it back to the original
 * state.
 */

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
	bool isPalindrome(ListNode* head) {
		if (head->next == NULL) {
			return true;
		}
		ListNode* slow = head;
		ListNode* fast = head;

		while (fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}

		// slow is the pointer at the middle point
		// reversing the linked list after the middle point

		ListNode* curr = slow;
		ListNode* nxt = curr->next;
		ListNode* last = NULL;

		while (curr != NULL) {
			if (curr->next == NULL) {
				slow = curr;
			}
			nxt = curr->next;
			curr->next = last;
			last = curr;
			curr = nxt;
		}

		while (slow != NULL) {
			if (slow->val != head->val) {
				return false;
			}
			slow = slow->next;
			head = head->next;
		}
		return true;
	}
};
