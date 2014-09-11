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
    ListNode *sortList(ListNode *head) {
        if (head == nullptr) return head;
        ListNode **phd = &head, **ptl = &head;
        while (*ptl != nullptr) ptl = &((*ptl)->next);
        while (true) {
            ListNode *left = head, *right, *start = head, *end;
            while (left->next != nullptr && left->val <= left->next->val) left = left->next;
            if (left->next == nullptr) break;
            right = left->next;
            while (right->next != nullptr && right->val <= right->next->val) right = right->next;
            if (right->next != nullptr) *phd = right->next;
            else ptl = &head;
            end = right;
            right = left->next;
            left->next = end->next = nullptr;
            left = start;
            while (left != nullptr && right != nullptr) {
                if (left->val < right->val) {
                    *ptl = left;
                    left = left->next;
                } else {
                    *ptl = right;
                    right = right->next;
                }
                ptl = &((*ptl)->next);
            }
            if (left != nullptr) *ptl = left;
            if (right != nullptr) *ptl = right;
            while (*ptl != nullptr) ptl = &((*ptl)->next);
        }
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
    int getLength(ListNode *head) {
      int res = 0;
      while (head) {
        head = head->next;
        ++ res;
      }
      return res;
    }
    ListNode *mergeList(ListNode *left, ListNode *right) {
      if (!left) return right;
      if (!right) return left;
      ListNode *res = NULL, *head = NULL;
      while (left || right) {
        ListNode *current = NULL;
        if (!left) current = right;
        else if (!right) current = left;
        else if (left->val < right->val) current = left;
        else current = right;
        if (current == left) left = left->next;
        else right = right->next;
        current->next = NULL;
        if (!res) res = head = current;
        else {
          res->next = current;
          res = res->next;
        }
      }
      return head;
    }
    ListNode *sortList(ListNode *head) {
      int len = getLength(head);
      if (len <= 1) return head;
      ListNode *mid = head, *last = NULL;
      for (int i = 0; i < len / 2; ++ i) {
        last = mid;
        mid = mid->next;
      }
      last->next = NULL;
      ListNode *left = sortList(head), *right = sortList(mid);
      return mergeList(left, right);
    }
};
