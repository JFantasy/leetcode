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
    void dfs(TreeNode *root, vector<int> &res) {
      if (!root) return;
      dfs(root->left, res);
      dfs(root->right, res);
      res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
      vector<int> res;
      dfs(root, res);
      return res;
    }
};
