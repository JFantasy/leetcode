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
    ListNode *deleteDuplicates(ListNode *head) {
      for (ListNode *current = head, *last = NULL; current; last = current, current = current->next) {
        if (!last) continue;
        if (current->val == last->val) {
          last->next = current->next;
          delete current;
          current = last;
        }
      }
      return head;
    }
};
