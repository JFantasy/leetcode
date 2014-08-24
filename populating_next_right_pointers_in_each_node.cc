/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
  public:
    void connect(TreeLinkNode *root) {
      for (TreeLinkNode *current = root; current; current = current->left) {
        if (!current->left) break;
        for (TreeLinkNode *head = current, *last = NULL; head; last = head, head = head->next) {
          head->left->next = head->right;
          if (last) last->right->next = head->left;
        }
      }
    }
};
