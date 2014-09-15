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
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> stk;
        vector<int> res;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *current = stk.top();
            stk.pop();
            if (current == nullptr) continue;
            res.push_back(current->val);
            stk.push(current->right);
            stk.push(current->left);
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
    void dfs(TreeNode *root, vector<int> &res) {
      if (!root) return;
      res.push_back(root->val);
      dfs(root->left, res);
      dfs(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode *root) {
      vector<int> res;
      dfs(root, res);
      return res;
    }
};
