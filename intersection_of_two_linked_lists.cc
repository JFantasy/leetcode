/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode *tailA = headA, *tailB = headB;
        while (tailA->next != nullptr) tailA = tailA->next;
        while (tailB->next != nullptr) tailB = tailB->next;
        if (tailA != tailB) return nullptr;
        int lenA = 0, lenB = 0;
        for (ListNode *current = headA; current != nullptr; current = current->next) ++lenA;
        for (ListNode *current = headB; current != nullptr; current = current->next) ++lenB;
        for (int i = 0; i < lenA - lenB; ++i) headA = headA->next;
        for (int i = 0; i < lenB - lenA; ++i) headB = headB->next;
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
