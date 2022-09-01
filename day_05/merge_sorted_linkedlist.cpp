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
        ListNode* ans = new ListNode();
        ListNode* ansc = ans;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                ansc->next = list1;
                list1 = list1->next;
            }
            else {
                ansc->next = list2;
                list2 = list2->next;
            }
            ansc = ansc->next;
        }
        if (list1 != NULL)ansc->next = list1;
        if (list2 != NULL)ansc->next = list2;

        return ans->next;
    }
};

// Optimised

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
        if (list1 == NULL)return list2;
        if (list2 == NULL)return list1;

        if (list1->val > list2->val)swap(list1, list2);
        ListNode* res = list1;

        while (list1 != NULL && list2 != NULL) {
            ListNode* tmp = list1;
            while (list1 != NULL && list1->val <= list2->val) {
                tmp = list1;
                list1 = list1->next;
            }
            tmp->next = list2;
            swap(list1, list2);
        }
        return res;
    }
};
