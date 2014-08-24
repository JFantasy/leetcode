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
    void dfs(TreeNode *root, int dep, vector<vector<int> > &res) {
      if (!root) return;
      if (dep == res.size()) res.push_back(vector<int>());
      res[dep].push_back(root->val);
      dfs(root->left, dep + 1, res);
      dfs(root->right, dep + 1, res);
    }
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
      vector<vector<int> > res;
      if (!root) return res;
      dfs(root, 0, res);
      for (int i = 1; i < res.size(); i += 2) reverse(res[i].begin(), res[i].end());
      return res;
    }
};
