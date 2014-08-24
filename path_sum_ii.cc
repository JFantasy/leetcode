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
    void dfs(vector<vector<int> > &res, vector<int> &current, TreeNode *root, int target) {
      current.push_back(root->val);
      if (!root->left && !root->right) {
        if (target == root->val) res.push_back(current);
      } else {
        if (root->left) dfs(res, current, root->left, target - root->val);
        if (root->right) dfs(res, current, root->right, target - root->val);
      }
      current.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
      vector<vector<int> > res;
      vector<int> current;
      if (root) dfs(res, current, root, sum);
      return res;
    }
};
