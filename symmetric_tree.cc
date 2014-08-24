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
    bool isMirror(TreeNode *root_l, TreeNode *root_r) {
      if (!root_l && !root_r) return true;
      if (!root_l || !root_r) return false;
      if (root_l->val != root_r->val) return false;
      return isMirror(root_l->left, root_r->right) && isMirror(root_l->right, root_r->left);
    }
    bool isSymmetric(TreeNode *root) {
      if (!root) return true;
      return isMirror(root->left, root->right);
    }
};
