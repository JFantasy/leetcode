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
    void dfs(TreeNode *root, vector<vector<int> > &res, int dep) {
      if (!root) return;
      if (dep == res.size()) res.push_back(vector<int>());
      res[dep].push_back(root->val);
      dfs(root->left, res, dep + 1);
      dfs(root->right, res, dep + 1);
    }
    vector<vector<int> > levelOrder(TreeNode *root) {
      vector<vector<int> > res;
      dfs(root, res, 0);
      return res;
    }
};
