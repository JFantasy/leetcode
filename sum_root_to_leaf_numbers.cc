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
    int dfs(TreeNode *root, int current) {
      if (!root) return 0;
      (current *= 10) += root->val;
      if (!root->left && !root->right) return current;
      return dfs(root->left, current) + dfs(root->right, current);
    }
    int sumNumbers(TreeNode *root) {
      return dfs(root, 0);
    }
};
