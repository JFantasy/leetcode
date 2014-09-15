
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        queue<TreeNode *> que;
        vector<vector<int> > res;
        vector<int> level;
        bool rev = false;
        que.push(root);
        que.push(nullptr);
        while (!que.empty()) {
            TreeNode *current = que.front();
            que.pop();
            if (current == nullptr) {
                if (level.empty()) continue;
                if (rev) reverse(level.begin(), level.end());
                res.push_back(level);
                que.push(nullptr);
                rev = !rev;
                level.clear();
            } else {
                level.push_back(current->val);
                if (current->left != nullptr) que.push(current->left);
                if (current->right != nullptr) que.push(current->right);
            }
        }
        return res;
    }
};

//---------

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
