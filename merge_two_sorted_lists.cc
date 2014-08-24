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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
      if (!l1 && !l2) return NULL;
      ListNode *res = l1;
      if (!l1 || (l2 && l1->val > l2->val)) res = l2;
      res->next = mergeTwoLists(l1 == res ? l1->next : l1, l2 == res ? l2->next : l2);
      return res;
    }
};
