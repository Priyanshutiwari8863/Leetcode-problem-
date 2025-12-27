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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            ListNode* pos = &dummy;
            while (pos->next && pos->next->val < curr->val) {
                pos = pos->next;
            }
            curr->next = pos->next;
            pos->next = curr;
            curr = nextNode;
        }
        return dummy.next;
    }
};
