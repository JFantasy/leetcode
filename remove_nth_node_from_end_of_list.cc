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
      ListNode **p = &head;
      ListNode *tail = head;
      while (n --) tail = tail->next;
      while (tail) {
        p = &(*p)->next;
        tail = tail->next;
      }
      ListNode *target = *p;
      *p = (*p)->next;
      delete target;
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
