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
      if (!head) return NULL;
      if (!head->next) return head;
      if (head->val == head->next->val) {
        for ( ; head->next && head->val == head->next->val; head = head->next);
        return deleteDuplicates(head->next);
      } else {
        head->next = deleteDuplicates(head->next);
        return head;
      }
    }
};
