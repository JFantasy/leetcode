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
      vector<TreeNode *> res;
      if (l > r) {
        res.push_back(NULL);
        return res;
      }
      for (int i = l; i <= r; ++ i) {
        vector<TreeNode *> left = dfs(l, i - 1), right = dfs(i + 1, r);
        for (int l = 0; l < left.size(); ++ l) {
          for (int r = 0; r < right.size(); ++ r) {
            TreeNode *current = new TreeNode(i);
            current->left = left[l];
            current->right = right[r];
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
