
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
    bool isValid(TreeNode *root, int low, int upp) {
        if (root == nullptr) return true;
        return isValid(root->left, low, root->val) && isValid(root->right, root->val, upp)
        && root->val > low && root->val < upp;
    }
    bool isValidBST(TreeNode *root) {
        return isValid(root, INT_MIN, INT_MAX);
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
