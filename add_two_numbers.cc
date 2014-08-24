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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      ListNode *res = new ListNode(0), *cur = res;
      int add = 0;
      while (l1 || l2 || add) {
        int lhs = !l1 ? 0 : l1->val, rhs = !l2 ? 0 : l2->val;
        cur->val = (lhs + rhs + add) % 10;
        add = (lhs + rhs + add) / 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
        if (l1 || l2 || add) {
          cur->next = new ListNode(0);
          cur = cur->next;
        }
      }
      return res;
    }
};
