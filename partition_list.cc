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
    ListNode *partition(ListNode *head, int x) {
      if (head == NULL) return NULL;
      ListNode *left = NULL, *right = NULL, *current;
      while (head) {
        ListNode *next = head->next;
        if (head->val < x) {
          head->next = left;
          left = head;
        } else {
          head->next = right;
          right = head;
        }
        head = next;
      }
      if (!left) return right;
      if (!right) return left;
      for (current = left; current->next; current = current->next);
      current->next = right;
      return left;
    }
};
