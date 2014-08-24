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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
      ListNode *l = head, *r = head, *res = head;
      while (n --) r = r->next;
      if (r == NULL) {
        res = head->next;
        delete head;
        return res;
      }
      while (r->next) {
        l = l->next;
        r = r->next;
      }
      ListNode *next = l->next;
      l->next = next->next;
      delete next;
      return res;
    }
};
