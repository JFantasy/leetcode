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
    vector<TreeNode *> dfs(int l, int r) {
      if (l > r) return vector<TreeNode *>({nullptr});
      vector<TreeNode *> res;
      for (int i = l; i <= r; ++ i) {
        vector<TreeNode *> left = dfs(l, i - 1), right = dfs(i + 1, r);
        for (const auto &l : left) {
          for (const auto &r : right) {
            TreeNode *current = new TreeNode(i);
            current->left = l;
            current->right = r;
            res.push_back(current);
          }
        }
      }
      return res;
    }
    vector<TreeNode *> generateTrees(int n) {
      return dfs(1, n);
    }
};
