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
    ListNode *reverseKGroup(ListNode *head, int k) {
      if (head == NULL) return NULL;
      if (k == 1) return head;
      int len;
      ListNode *current = head;
      for (len = 0; len < k && current; ++ len) current = current->next;
      if (len < k) return head;
      current = head->next;
      ListNode *last = head;
      for (int i = 0; i < k - 1; ++ i) {
        ListNode *next = current->next;
        current->next = last;
        last = current;
        current = next;
      }
      head->next = reverseKGroup(current, k);
      return last;
    }
};
