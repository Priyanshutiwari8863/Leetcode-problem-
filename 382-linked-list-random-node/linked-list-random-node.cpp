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
    ListNode* head;
    random_device rd;
    mt19937 gen;
public:
    Solution(ListNode* head) : head(head), gen(rd()) {}

    int getRandom() {
        ListNode* curr = head;
        int reservoir = curr->val;
        int n = 1;
        curr = curr->next;

        while (curr) {
            n++;
            uniform_int_distribution<> dis(1, n);
            if (dis(gen) == n) reservoir = curr->val;
            curr = curr->next;
        }
        return reservoir;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */