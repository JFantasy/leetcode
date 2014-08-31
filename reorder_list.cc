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
      ListNode **p = &head;
      ListNode *begin = *p, *current = head;
      while (current) {
        ListNode *next = current->next;
        current->next = *p;
        *p = current;
        current = next;
      }
      begin->next = nullptr;
      return head;
    }
    void mergeList(ListNode *left, ListNode *right) {
      while (left->next != nullptr) {
        ListNode *next = left->next;
        left->next = right;
        right = right->next;
        left->next->next = next;
        left = next;
      }
      left->next = right;
    }
    void reorderList(ListNode *head) {
      if (head == nullptr || head->next == nullptr) return;
      ListNode *fast = head, *slow = head, *prev = head;
      while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
      }
      prev->next = nullptr;
      mergeList(head, reverse(slow));
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
    ListNode *reverse(ListNode *head) {
      if (!head->next) return head;
      ListNode *last = head, *current = head->next;
      last->next = NULL;
      while (current) {
        ListNode *next = current->next;
        current->next = last;
        last = current;
        current = next;
      }
      return last;
    }
    void merge(ListNode *l, ListNode *r) {
      ListNode *current = l;
      l = l->next;
      current->next = NULL;
      int col = 0;
      while (l || r) {
        col ^= 1;
        if (col && r) {
          current->next = r;
          r = r->next;
        } else {
          current->next = l;
          l = l->next;
        }
        current = current->next;
        current->next = NULL;
      }
    }
    void reorderList(ListNode *head) {
      if (!head || !head->next) return;
      int length = 1;
      for (ListNode *current = head; current; current = current->next) ++ length;
      ListNode *current = head, *last = NULL;
      for (int i = 0; i < length / 2; ++ i) {
        last = current;
        current = current->next;
      }
      last->next = NULL;
      ListNode *l = head, *r = current;
      r = reverse(r);
      merge(l, r);
    }
};
