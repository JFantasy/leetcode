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
    int dfs(TreeNode *root, int &ans) {
      if (root == NULL) return 0;
      int left_val = max(0, dfs(root->left, ans)), right_val = max(0, dfs(root->right, ans));
      ans = max(ans, root->val + left_val + right_val);
      return root->val + max(left_val, right_val);
    }
    int maxPathSum(TreeNode *root) {
      int res = root->val;
      dfs(root, res);
      return res;
    }
};
