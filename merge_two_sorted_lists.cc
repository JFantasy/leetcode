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
      ListNode *head = NULL;
      ListNode **p = &head;
      while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
          *p = l1;
          l1 = l1->next;
        } else {
          *p = l2;
          l2 = l2->next;
        }
        p = &((*p)->next);
      }
      if (l1) *p = l1;
      if (l2) *p = l2;
      return head;
    }
};

//---------

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
