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
    bool hasCycle(ListNode *head) {
      ListNode* l = head, *r = head;
      while (r != NULL) {
        l = l->next;
        r = r->next;
        r = !r ? NULL : r->next;
        if (l && r && l == r) return true;
      };
      return false;
    }
};
