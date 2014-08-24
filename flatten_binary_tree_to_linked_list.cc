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
    void flatten(TreeNode *root) {
      if (root == NULL) return;
      flatten(root->left);
      flatten(root->right);
      TreeNode *current = root->left;
      if (!current) return;
      for ( ; current->right; current = current->right);
      current->right = root->right;
      root->right = root->left;
      root->left = NULL;
    }
};
