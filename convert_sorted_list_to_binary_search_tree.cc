/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    TreeNode *build(ListNode *low, ListNode *upp) {
      if (!low || low == upp) return NULL;
      int length = 0;
      ListNode *current;
      for (current = low; current != upp; current = current->next) ++ length;
      int mid = length >> 1;
      current = low;
      for (int i = 0; i < mid; ++ i, current = current->next);
      TreeNode *res = new TreeNode(current->val);
      res->left = build(low, current);
      res->right = build(current->next, upp);
      return res;
    }
    TreeNode *sortedListToBST(ListNode *head) {
      return build(head, NULL);
    }
};
