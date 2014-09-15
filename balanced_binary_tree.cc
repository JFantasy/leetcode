
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
    int getHeight(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = getHeight(root->left), right = getHeight(root->right);
        if (left < 0 || right < 0 || abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return getHeight(root) >= 0;
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
    bool check(TreeNode *root, int &height) {
      if (!root) {
        height = 0;
        return true;
      }
      int left_height, right_height;
      bool res = check(root->left, left_height);
      res &= check(root->right, right_height);
      res &= (abs(left_height - right_height) <= 1);
      height = max(left_height, right_height) + 1;
      return res;
    }
    bool isBalanced(TreeNode *root) {
      int height;
      return check(root, height);
    }
};
