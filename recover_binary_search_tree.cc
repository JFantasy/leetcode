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
    void dfs(TreeNode *root, TreeNode **p, TreeNode **q, TreeNode **pre) {
      if (!root) return;
      dfs(root->left, p, q, pre);
      if (*pre && (*pre)->val > root->val) {
        if (!(*p)) *p = *pre;
        *q = root;
      }
      *pre = root;
      dfs(root->right, p, q, pre);
    }
    void recoverTree(TreeNode *root) {
      TreeNode *p = NULL, *q = NULL, *pre = NULL;
      dfs(root, &p, &q, &pre);
      if (p && q) swap(p->val, q->val);
    }
};
