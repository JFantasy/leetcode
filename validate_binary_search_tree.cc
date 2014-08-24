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
    void dfs(TreeNode *root, bool &res, bool &first, int &last) {
      if (!root) return;
      dfs(root->left, res, first, last);
      if (!first && last >= root->val) res = false;
      first = false;
      last = root->val;
      dfs(root->right, res, first, last);
    }
    bool isValidBST(TreeNode *root) {
      bool res = true, first = true;
      int last;
      dfs(root, res, first, last);
      return res;
    }
};
