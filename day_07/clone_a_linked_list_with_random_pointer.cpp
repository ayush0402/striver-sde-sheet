/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)return head;

        Node* headcopy = head;
        // Step 1 : Inserting deep copy in between.
        while (headcopy != NULL) {
            Node* deepcopy = new Node(headcopy->val);
            Node* front = headcopy->next;
            headcopy->next = deepcopy;
            deepcopy->next = front;
            headcopy = front;
        }

        Node* deepcopyhead = head->next;

        // Step 2 : Attaching random pointers of the deep copy.
        Node* iter = head;
        while (iter != NULL) {
            if (iter->random == NULL) {
                iter->next->random = NULL;
            }
            else iter->next->random = iter->random->next;
            iter = iter->next->next;
        }

        // Step 3 : Clearing up the mess, aka resolving next pointers.
        Node* dummy = new Node(0);
        dummy->next = deepcopyhead;
        iter = head;
        Node* front = iter->next->next;
        while (iter != NULL) {
            front = iter->next->next;
            dummy->next = iter->next;
            iter->next = front;
            iter = iter->next;
            dummy = dummy->next;
        }
        return deepcopyhead;
    }
};
