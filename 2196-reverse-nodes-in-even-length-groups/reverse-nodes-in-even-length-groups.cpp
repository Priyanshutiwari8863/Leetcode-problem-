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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prev = head;
        int group_len = 2;
        
        while (prev->next != nullptr) {
            ListNode* curr = prev->next;
            ListNode* curr_tail = curr;
            int actual_len = 0;
            
            while (actual_len < group_len && curr_tail != nullptr) {
                actual_len++;
                curr_tail = curr_tail->next;
            }
            
            if (actual_len % 2 == 0) {
                ListNode* tail = curr; 
                ListNode* p = nullptr;
                ListNode* c = curr;
                ListNode* n = nullptr;
                
                for (int i = 0; i < actual_len; i++) {
                    n = c->next;
                    c->next = p;
                    p = c;
                    c = n;
                }
                
                prev->next = p;
                tail->next = c;
                prev = tail;
            } else {
                for (int i = 0; i < actual_len; i++) {
                    prev = prev->next;
                }
            }
            
            group_len++;
        }
        
        return head;
    }
};