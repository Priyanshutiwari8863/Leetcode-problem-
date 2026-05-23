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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;
        
        while (true) {
            ListNode* kth = getKthNode(groupPrev, k);
            if (!kth) break; 
            
            ListNode* groupNext = kth->next;
            
            
            ListNode* prev = groupNext; 
            ListNode* curr = groupPrev->next;
            ListNode* nextNode = nullptr;
            
            while (curr != groupNext) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            
            
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp; 
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }

private:
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};