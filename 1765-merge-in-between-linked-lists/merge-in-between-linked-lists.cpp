class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prevA = list1;
        for (int i = 0; i < a - 1; ++i) {
            prevA = prevA->next;
        }

        ListNode* nodeB = prevA;
        for (int i = 0; i <= b - a + 1; ++i) {
            nodeB = nodeB->next;
        }

        prevA->next = list2;

        ListNode* tail2 = list2;
        while (tail2->next) {
            tail2 = tail2->next;
        }

        tail2->next = nodeB;

        return list1;
    }
};