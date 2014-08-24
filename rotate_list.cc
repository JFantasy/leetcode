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
    ListNode *rotateRight(ListNode *head, int k) {
      if (!head) return NULL;
      int len = 0;
      for (ListNode *current = head; current; current = current->next, ++ len);
      k = len - k % len;
      if (k == len) return head;
      ListNode *res = head, *tail = NULL;
      for (int i = 0; i < k; ++ i, res = res->next);
      for (tail = res; tail->next; tail = tail->next);
      tail->next = head;
      for ( ; head->next != res; head = head->next);
      head->next = NULL;
      return res;
    }
};
