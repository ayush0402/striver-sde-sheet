/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
	Bruteforces approach :

	Iterate other linked list for every node in the first
	linked list and check if any node in the other linked
	list matches the node from the first linked list.
	Time Complexity : O(n*m)
	Space Complexity : O(1)

	A optimisation for the time complexity can be to use hasing
	Store ListNode* addresses in a set for one linked list and then
	start iterating the other linked list checking if the ListNode*
	address already exists in the set.
	Time Complexity : O(n+m)
	Space Complexity : O(n+m)
*/

/*
	https://youtu.be/u4FWXfgS8jw

	Optimised approach :

	Find the length of both the linked list and then increment
	the head of the longer linked list by the difference in their length.

	Then iterate the pointers on both the linked list simultanously and the
	node where they collide is the answer.
	(Lengthier, so the next approach is preferred.)
	Time Complexity : O(max(n,m))
	Space Complexity : O(1)
*/

class Solution1 {
private:
	int lengthOfLinkedList(ListNode* head) {
		int res = 0;
		while (head != NULL) {
			res++;
			head = head->next;
		}
		return res;
	}
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		// Optimised approach 1
		int n = lengthOfLinkedList(headA);
		int m = lengthOfLinkedList(headB);
		int diff = abs(n - m);
		if (n > m) {
			while (diff--) {
				headA = headA->next;
			}
		}
		else {
			while (diff--) {
				headB = headB->next;
			}
		}

		while (headA != headB) {
			headA = headA->next;
			headB = headB->next;
		}
		return headA;
	}
};


/*
	Optimised approach 2 :
	(Preferred Approach)

	Take two dummy nodes pointing to head of each linked lists.
	Iterate both the dummy nodes simultanously until they collide,
	If any dummy node reaches the end of the linked list, put it back
	at the head of the linked list.
	(Concise and Crisper code)
	Time Complexity : O(max(n,m))
	Space Complexity : O(1)
*/

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* dA = headA;
		ListNode* dB = headB;

		while (dA != dB) {
			dA = dA->next;
			dB = dB->next;
			if (dA == NULL && dB != NULL)dA = headA;
			if (dB == NULL && dA != NULL)dB = headB;
		}
		return dA;
	}
};
