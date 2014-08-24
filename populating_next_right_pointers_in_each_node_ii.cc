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
      while (root) {
        TreeLinkNode *next_root = NULL;
        for (TreeLinkNode *current = root, *last = NULL; current; current = current->next) {
          if (!next_root) {
            if (current->left) next_root = current->left;
            else if (current->right) next_root = current->right;
          }
          if (!current->left && !current->right) continue;
          else if (!current->left || !current->right) {
            TreeLinkNode *child = !current->left ? current->right : current->left;
            if (last) last->next = child;
            last = child;
          } else {
            if (last) last->next = current->left;
            current->left->next = current->right;
            last = current->right;
          }
        }
        root = next_root;
      }
    }
};
