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
    ListNode *swapList(ListNode *current) {
      if (current == NULL) return NULL;
      if (current->next == NULL) return current;
      ListNode *l = current, *r = current->next, *next = r->next;
      r->next = l;
      l->next = swapList(next);
      return r;
    }
    ListNode *swapPairs(ListNode *head) {
      return swapList(head);
    }
};
