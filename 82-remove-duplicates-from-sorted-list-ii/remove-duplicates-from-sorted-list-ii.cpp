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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy; // last node before duplicates
        ListNode* curr = head;

        while (curr != NULL) {
            bool duplicate = false;

            // Skip all nodes with same value
            while (curr->next != NULL && curr->val == curr->next->val) {
                duplicate = true;
                curr = curr->next;
            }

            if (duplicate) {
                // Remove all duplicates
                prev->next = curr->next;
            } else {
                // No duplicate, move prev
                prev = prev->next;
            }

            curr = curr->next;
        }

        return dummy->next;
    }
};
