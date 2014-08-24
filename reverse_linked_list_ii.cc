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
    ListNode *reverse(ListNode *head) {
      if (!head) return NULL;
      if (!head->next) return head;
      ListNode *last = head, *current = head->next;
      head->next = NULL;
      while (current) {
        ListNode *next = current->next;
        current->next = last;
        last = current;
        current = next;
      }
      return last;
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) {
      ListNode *left = NULL, *right = head, *current = head;
      for (int i = 1; i < n; ++ i) {
        if (i < m) left = current;
        right = right->next;
        current = current->next;
      }
      ListNode *next = NULL;
      if (right) {
        next = right->next;
        right->next = NULL;
      }
      ListNode *res;
      if (!left) res = reverse(head);
      else {
        res = head;
        left->next = reverse(left->next);
      }
      for (current = res; current->next; current = current->next);
      current->next = next;
      return res;
    }
};
